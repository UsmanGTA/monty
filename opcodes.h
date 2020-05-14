#ifndef _OPCODES_H
#define _OPCODES_H

instruction_t opcodes[] = {
		{"pall", pall_s},
		{"pop", pop_s},
		{"add", add_s},
		{"pint", pint_s},
		{"swap", swap_s},
		{"sub", sub_s},
		{"mul", mul_s},
		{"div", div_s},
		{"mod", mod_s},
		{"pchar", pchar_s},
		{"pstr", pstr_s},
		{ NULL, NULL },
	};

#endif
