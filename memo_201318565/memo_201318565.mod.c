#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x132abf8a, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x6b9a4cc1, __VMLINUX_SYMBOL_STR(single_release) },
	{ 0xda3971dc, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0xeef0c4f6, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0xb2e7a2c6, __VMLINUX_SYMBOL_STR(remove_proc_entry) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xbb3fc384, __VMLINUX_SYMBOL_STR(proc_create) },
	{ 0x40c7247c, __VMLINUX_SYMBOL_STR(si_meminfo) },
	{ 0x234f4ea3, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0xc3566018, __VMLINUX_SYMBOL_STR(single_open) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

