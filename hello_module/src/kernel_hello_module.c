/*
 ============================================================================
 Name        : kernel_hello_module.c
 Author      : Jeremy Hunt
 Version     : 1.0
 Copyright   : Dual BSD/GPL
 Description : Hello World in C, Kernel Module Style
 ============================================================================
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <mach/gpio.h>

static int hello_init(void) {
	printk(KERN_ALERT "Hello, world\n");
	at91_set_gpio_value(AT91_PIN_PB10, 1);
	return 0;
}

static void hello_exit(void) {
	printk(KERN_ALERT "Goodbye, cruel world\n");
	at91_set_gpio_value(AT91_PIN_PB10, 0);
}

module_init(hello_init);
module_exit(hello_exit);


MODULE_LICENSE("Dual BSD/GPL");
