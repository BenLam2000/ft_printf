/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 22:56:55 by belam             #+#    #+#             */
/*   Updated: 2026/03/08 05:09:31 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>  // only for printing results REMOVE THIS
#include "ft_printf.h"

// TODO:
// refactor to meet norm
// input type is not same as specifier
// number of arguments not matching format string
// restructure folder to have src, incl, obj...
// README
// .gitignore all unused files for submission + make a standard reusable .gitignore template

// future: variadic function that can be reusable to build things like atoi and format_is_valid, for any number of sets of characters, each with a set count or unlimited/optional


// DONE:
// check for correct format before conversion to prevent segmentation fault
// handle invalid specifiers/flags
// flags in any order or combination
// return value
// ft_atoi_end
// . flag
// makefile
// tester file
// check for NULL input or ""
// change structs to typedefs
// move ft_itoa_base and 64 into root dir, remove declaration from libft/libft.h & libft/Makefile and add to ft_printf.h and Makefile
// replace const strings with macros (radix)
// readd NULL malloc checking in ft_itoa_base and 64

// '/0' terminator is included in strchr check, so ft_strchr(anything, '\0') == true
/////////////////////////////////////

// ptr passed is pointing at %-0d
//                            ^ 
// need to take note which flags are mutually exclusive (won't appear tgt side by side)
// - : for any conversion
// 0 : only numbers
// + and ' ': only signed numbers
// handles repeating valid flags and in any sequence, ex: "%00#-5d"
// ft_atoi only returns int, but have to traverse manually after that, so integrate
// traversing into ft_atoi_end, modifying the char * directly
static void	handle_flags(const char **format_str, t_flags *ptr_flags)
{
	while (ft_strchr("-0# +", **format_str))
	{
		if (**format_str == '-')
			ptr_flags->align_left = 1;
		else if (**format_str == '0')
			ptr_flags->pad_zero = 1;
		else if (**format_str == '#')
			ptr_flags->alt_form = 1;
		else if (**format_str == ' ')
			ptr_flags->sign_space = 1;
		else if (**format_str == '+')
			ptr_flags->sign_plus = 1;
		(*format_str)++;
	}
}

static void	handle_width(const char **format_str, t_flags *ptr_flags)
{
	if (ft_isdigit(**format_str))
		ptr_flags->width = ft_atoi_end(format_str);
}

static void	handle_precision(const char **format_str, t_flags *ptr_flags)
{
	if (**format_str == '.')
	{
		ptr_flags->exp_prec = 1;
		(*format_str)++;
	}
	if (ft_isdigit(**format_str))
		ptr_flags->precision = ft_atoi_end(format_str);
	ptr_flags->spec = **format_str;
	if (ft_strchr("pdiuxX", ptr_flags->spec) && !ptr_flags->exp_prec)
		ptr_flags->precision = 1;
}

void	get_flags(const char **format_str, t_flags *p_flags,
	t_features *p_features, va_list args)
{
	(*format_str)++;
	handle_flags(format_str, p_flags);
	handle_width(format_str, p_flags);
	handle_precision(format_str, p_flags);
	handle_conv(args, p_flags, p_features);
	(*format_str)++;
}


// if specifier is invalid, print % until before specifier
// ex: % -2.2z -> print: % -2.2
// this function sets:
// ptr_flags->neg_num
// ptr_flags->conv_len
// ptr_features->conv




/////////////////////////


// NULL handled in here because ft_strdup(NULL) causes seg fault (accessing NULL ptr)
static void	handle_s_conv(t_flags *ptr_flags, t_features *ptr_features, va_list args)
{
	const char	*str;

	str = va_arg(args, const char *);
	if (str == (char *)0)
	{
		if (ptr_flags->exp_prec && ptr_flags->precision < 6)
			ptr_features->conv = ft_strdup("");
		else
			ptr_features->conv = ft_strdup("(null)");
	}
	else
	{
		if (ptr_flags->exp_prec)
			ptr_features->conv = ft_substr(str, 0, ptr_flags->precision);
		else
			ptr_features->conv = ft_strdup(str);
	}
}

static void	handle_di_conv(t_flags *ptr_flags, t_features *ptr_features, va_list args)
{		
	int	num;
	
	num = va_arg(args, int);
	if (num < 0)
	{
		ptr_flags->neg_num = 1;
		num = -num;
	}
	ptr_features->conv = ft_itoa_base(num, RADIX_D, 0);
}

static void	handle_zero_conv(t_flags *ptr_flags, t_features *ptr_features)
{
	if (!ft_strncmp(ptr_features->conv, "0", 10))
	{
		ptr_flags->is_zero = 1;
		if (ptr_flags->spec == 'p')
		{
			free(ptr_features->conv);
			ptr_features->conv = ft_strdup("(nil)");
		}
		else if (ft_strchr("diuxX", ptr_flags->spec) && ptr_flags->precision == 0)
		{
			free(ptr_features->conv);
			ptr_features->conv = ft_strdup("");
		}
	}
}

static void	set_conv_len(t_flags *ptr_flags, t_features *ptr_features)
{
	if (ft_strchr("spdiuxX%", ptr_flags->spec))
		ptr_flags->conv_len = ft_strlen(ptr_features->conv);
	else if (ptr_flags->spec == 'c')
		ptr_flags->conv_len = 1;
}

// ft_itoa_base takes num as int (32 bit), but uintptr_t is 64 bit, so it gets truncated
void	handle_conv(va_list args, t_flags *ptr_flags, t_features *ptr_features)
{
	if (ptr_flags->spec == 'c')
	{
		ptr_features->conv = ft_strdup(" ");
		ptr_features->conv[0] = (unsigned char)va_arg(args, int);
	}
	else if (ptr_flags->spec == 's')
		handle_s_conv(ptr_flags, ptr_features, args);
	else if (ptr_flags->spec == 'p')
		ptr_features->conv = ft_itoa_base_64((uintptr_t)va_arg(args, void *),
		RADIX_X, 0);
	else if (ptr_flags->spec == 'd' || ptr_flags->spec == 'i')
		handle_di_conv(ptr_flags, ptr_features, args);
	else if (ptr_flags->spec == 'u')
		ptr_features->conv = ft_itoa_base(va_arg(args, unsigned int), RADIX_D, 0);
	else if (ptr_flags->spec == 'x')
		ptr_features->conv = ft_itoa_base(va_arg(args, unsigned int), RADIX_X, 0);
	else if (ptr_flags->spec == 'X')
		ptr_features->conv = ft_itoa_base(va_arg(args, unsigned int), RADIX_XX, 0);
	else if (ptr_flags->spec == '%')
		ptr_features->conv = ft_strdup("%");
	handle_zero_conv(ptr_flags, ptr_features);
	set_conv_len(ptr_flags, ptr_features);
}



///////////////////////////////

static void	handle_padchar_sign(t_flags *ptr_flags, t_features *ptr_features)
{
	if (ptr_flags->pad_zero && !ptr_flags->align_left 
		&& (ft_strchr("diuxX", ptr_flags->spec) || (ptr_flags->spec == 'p'
		&& !ptr_flags->is_zero)) && !ptr_flags->exp_prec)
		ptr_features->pad_char = '0';
	if (ft_strchr("di", ptr_flags->spec) || (ptr_flags->spec == 'p' \
		&& ft_strncmp(ptr_features->conv, "(nil)", 20)))
	{
		if (ptr_flags->neg_num)
			ptr_features->sign_char = "-";
		else
		{
			if (ptr_flags->sign_space)
				ptr_features->sign_char = " ";
			if (ptr_flags->sign_plus)
				ptr_features->sign_char = "+";
		}
	}
}

static void	handle_alt(t_flags *p_flags, t_features *p_features)
{
	if ((p_flags->alt_form && p_flags->spec == 'x' && !p_flags->is_zero)
		|| (p_flags->spec == 'p' && !p_flags->is_zero))
		p_features->alt_form_prefix = "0x";
	else if (p_flags->alt_form && p_flags->spec == 'X' && !p_flags->is_zero)
		p_features->alt_form_prefix = "0X";
}

static void	handle_padding(t_flags *p_flags, t_features *p_features)
{
	int fill_count;

	fill_count = ft_strlen(p_features->sign_char)
		+ ft_strlen(p_features->alt_form_prefix)
		+ ft_max(p_flags->conv_len, p_flags->precision);
	if (p_flags->width > fill_count && ft_strchr("cspdiuxX", p_flags->spec))
	{
		if (p_flags->align_left)
			p_features->pad_right_count = p_flags->width - fill_count;
		else
			p_features->pad_left_count = p_flags->width - fill_count;
	}
}

static void	handle_prec(t_flags *p_flags, t_features *p_features)
{
	if (p_flags->precision > p_flags->conv_len
		&& (ft_strchr("diuxX", p_flags->spec) ||
		(p_flags->spec == 'p'&& !p_flags->is_zero)))
		p_features->prec_pad_count = p_flags->precision - p_flags->conv_len;
}

void	flags_to_features(t_flags *ptr_flags, t_features *ptr_features)
{
	handle_padchar_sign(ptr_flags, ptr_features);
	handle_alt(ptr_flags, ptr_features);
	handle_padding(ptr_flags, ptr_features);
	handle_prec(ptr_flags, ptr_features);
}






////////////////////////

static void	print_pad(unsigned int pad_count, char pad_char, int *p_bytes)
{
	unsigned int	count;

	count = 0;
	while (count < pad_count)
	{
		ft_putchar_fd(pad_char, 1);
		count++;
	}
	*p_bytes += pad_count;
}


static void	print_sign_alt(t_features *p_features, char pad_char, int *p_bytes)
{
	if (p_features->pad_char == pad_char)
	{
		*p_bytes += ft_putstr_fd_b(p_features->sign_char, 1);
		*p_bytes += ft_putstr_fd_b(p_features->alt_form_prefix, 1);
	}
}

static void	print_prec_pad(unsigned int pad_count, int *p_bytes)
{
	print_pad(pad_count, '0', p_bytes);
}

static void	print_conv(t_flags *p_flags, t_features *p_features, int *p_bytes)
{
	ft_putstr_fd(p_features->conv, 1);
	*p_bytes += p_flags->conv_len;
	free(p_features->conv);
}

void	print_features(t_flags *p_flags, t_features *p_features, int *p_bytes)
{
	print_sign_alt(p_features, '0', p_bytes);
	print_pad(p_features->pad_left_count, p_features->pad_char, p_bytes);
	print_sign_alt(p_features, ' ', p_bytes);
	print_prec_pad(p_features->prec_pad_count, p_bytes);
	print_conv(p_flags, p_features, p_bytes);
	print_pad(p_features->pad_right_count, p_features->pad_char, p_bytes);
}



////////////////////////////

static void print_t_flags(t_flags *ptr_flags)
{
	printf("align_left:%d,\npad_zero:%d,\nalt_form:%d,\nsign_space:%d,\nsign_plus:%d,\nwidth:%d,\nprecision:%d,\nneg_num:%d,\nconv_len:%d,\nspec:%c,\n", ptr_flags->align_left, ptr_flags->pad_zero, ptr_flags->alt_form, ptr_flags->sign_space, ptr_flags->sign_plus, ptr_flags->width, ptr_flags->precision, ptr_flags->neg_num, ptr_flags->conv_len, ptr_flags->spec);
}

static void print_t_features(t_features *ptr_features)
{
	printf("pad_char:%c,\npad_left_count:%u,\npad_right_count:%u,\nprec_pad_count:%u,\nsign_char:%s,\nalt_form_prefix:%s,\nconv:%s\n", ptr_features->pad_char, ptr_features->pad_left_count, ptr_features->pad_right_count, ptr_features->prec_pad_count, ptr_features->sign_char, ptr_features->alt_form_prefix, ptr_features->conv);
}

void	debug_print(const char *format_str, t_flags *p_flags, 
	t_features *p_features, const char *msg)
{
	printf("%s", msg);
	print_t_flags(p_flags);
	print_t_features(p_features);
	printf("%s\n", format_str);
}

/*
// for o,x,X: regardless of which base is set as input 0x, 0b, 0, decimal, compiler will autotranslate and stores as binary in RAM
// cases: %z (invalid specifier)
int	main(int argc, char *argv[])
{
	//struct s_features features = {.pad_char = ' ', .pad_left_count = 0, .pad_right_count = 3, .sign_char = "", .width = -5};
	//print_features(&features, conv);
	if (argc == 4)
	{
		int a = 2;
		int b;
		if (argv[3][0] == 'c')
			b = ft_printf(argv[1], argv[2][0]);
		else if (argv[3][0] == 's')
			b = ft_printf(argv[1], argv[2]);
		else if (argv[3][0] == 'p')
			b = ft_printf(argv[1], (void *)&a);
		else if (argv[3][0] == 'x' || argv[3][0] == 'X')
			b = ft_printf(argv[1], atoi(argv[2]));
		else if (argv[3][0] == 'd' || argv[3][0] == 'i' || argv[3][0] == 'u')
			b = ft_printf(argv[1], atoi(argv[2]));
		printf("\nbytes printed:%d\n", b);
	}
	else if (argc == 2)
	{
		printf("%d" , format_is_valid(argv[1]));
	}
	return (0);
}*/
///////////////////////////////////

static int	format_is_valid(const char *format_str)
{
	while (ft_strchr("-0# +", *format_str) && *format_str)
		format_str++;
	while (ft_isdigit(*format_str))
		format_str++;
	if (*format_str == '.')
		format_str++;
	while (ft_isdigit(*format_str))
		format_str++;
	if (ft_strchr(SPECS, *format_str) && *format_str)
		return (1);
	return (0);
}

static void	set_defaults(t_flags *p_flags, t_features *p_features)
{
	*p_flags = (t_flags){0};
	*p_features = (t_features){
		.pad_char = ' ',
		.pad_left_count = 0,
		.pad_right_count = 0,
		.prec_pad_count = 0,
		.sign_char = "",
		.alt_form_prefix = "",
		.conv = ""
		};
}

int	ft_printf(const char *format_str, ...)
{
	va_list		args;
	int			bytes_written;
	t_flags		flags;
	t_features	features;

	va_start(args, format_str);	
	bytes_written = 0;
	while (*format_str)
	{
		if (*format_str == '%' && format_is_valid(format_str + 1))
		{
			set_defaults(&flags, &features);
			get_flags(&format_str, &flags, &features, args);
			flags_to_features(&flags, &features);
			print_features(&flags, &features, &bytes_written);
		}
		else
		{
			ft_putchar_fd(*format_str, 1);
			bytes_written++;
			format_str++;
		}
	}
	va_end(args);
	return (bytes_written);
}
