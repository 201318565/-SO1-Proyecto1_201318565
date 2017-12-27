#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/hugetlb.h>
#include <linux/mm.h>
#include <linux/mman.h>
#include <linux/mmzone.h>
#include <linux/quicklist.h>
#include <linux/swap.h>
#include <linux/swapfile.h>
#include <linux/vmstat.h>
#include <linux/atomic.h>

struct sysinfo i;


static int memo_proc_show(struct seq_file *m, void *v) {
	long p;
  seq_printf(m, "******************************************start***********************\n");
  seq_printf(m, "*201318565*\n");
  seq_printf(m, "*Gilberto Antonio Rosales Vaquin*\n");
  seq_printf(m, "*Debian 9*\n");
	
	#define K(x) ((x) << (PAGE_SHIFT - 10))
	si_meminfo(&i);
	seq_printf(m,"RAM Total: %8lu kB \n", K(i.totalram));
	seq_printf(m,"RAM Libre: %8lu kB \n", K(i.freeram));
	p = (100-(i.freeram * 100)/ i.totalram); 
	seq_printf(m,"Porcentaje RAM Uilizada: %8lu \n", p);
	#undef K

  seq_printf(m, "******************************************end*************************\n");
  return 0;
}

static int memo_proc_open(struct inode *inode, struct  file *file) {
  return single_open(file, memo_proc_show, NULL);
}

static const struct file_operations memo_proc_fops = {
  .owner = THIS_MODULE,
  .open = memo_proc_open,
  .read = seq_read,
  .llseek = seq_lseek,
  .release = single_release,
};

static int __init memo_proc_init(void) {
  proc_create("memo_proc", 0, NULL, &memo_proc_fops);
  printk(KERN_INFO "201318565\n");
  return 0;
}

static void __exit memo_proc_exit(void) {
  remove_proc_entry("memo_proc", NULL);
  printk(KERN_INFO "Sistemas Operativos 1\n");
}

MODULE_LICENSE("GPL");
module_init(memo_proc_init);
module_exit(memo_proc_exit);
