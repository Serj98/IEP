#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>


static int __init exemplu_start(void)
{
	printk(KERN_INFO "hello, world! \n");
	return 0;
}

static void __exit exemplu_end(void)
{
	printk(KERN_INFO "goodbye world \n");
}

module_init(exemplu_start);
module_exit(exemplu_end);
