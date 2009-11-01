#include <multiboot.h>
#include <system.h>

void mbinfo(unsigned long magic, unsigned long addr)
{
	cls();
	printk("\n%x\n", magic);
	multiboot_info_t *mbi;
	if(magic != MULTIBOOT_BOOTLOADER_MAGIC){
		printk("Invalid magic number: 0x%x\n", (unsigned) magic);
		for(;;);
	}
         
	mbi = (multiboot_info_t *) addr;
     
	/* Are mem_* valid? */
	if(CHECK_FLAG (mbi->flags, 0)){
		printk("memory lower = %uKB, memory upper = %uKB\n", (unsigned) mbi->mem_lower, (unsigned) mbi->mem_upper);
		printk("Total memory %uKB\n\n", (unsigned) mbi->mem_lower + (unsigned) mbi->mem_upper);
	}
     
	/* Are mods_* valid? */
	if(CHECK_FLAG (mbi->flags, 3)){
		module_t *mod;
		int i;
     
		printk("mods_count = %d, mods_addr = 0x%x\n", (int) mbi->mods_count, (int) mbi->mods_addr);
		for(i = 0, mod = (module_t *)mbi->mods_addr;i < mbi->mods_count;
		i++, mod += sizeof (module_t))
		printk(" mod_start = 0x%x, mod_end = 0x%x, string = %s\n", (unsigned) mod->mod_start,(unsigned) mod->mod_end,(char *) mod->string);
	}
	
	/* Are mmap_* valid? */
   	if (CHECK_FLAG (mbi->flags, 6)){
           memory_map_t *mmap;
     
           printk("mmap_addr = 0x%x, mmap_length = 0x%x\n", (unsigned) mbi->mmap_addr, (unsigned) mbi->mmap_length);
           for(mmap = (memory_map_t *) mbi->mmap_addr;
			(unsigned long) mmap < mbi->mmap_addr + mbi->mmap_length;
			mmap = (memory_map_t *) ((unsigned long) mmap + mmap->size + sizeof (mmap->size)))
				printk(" size = 0x%x, base_addr = 0x%x%x,"
                     " length = 0x%x%x, type = 0x%x\n",
                     (unsigned) mmap->size,
                     (unsigned) mmap->base_addr_high,
                     (unsigned) mmap->base_addr_low,
                     (unsigned) mmap->length_high,
                     (unsigned) mmap->length_low,
                     (unsigned) mmap->type);
	}

	/* VBE info is present? 
	 *	More will be done with this later as the kernel progresses.
	 */
	if (CHECK_FLAG (mbi->flags, 11)){
		printk("Oh yeah\n");
	}
	
	printk("Total memory %uKB\n\n", (unsigned) mbi->mem_lower + (unsigned) mbi->mem_upper);
	printk("\n\n");
}

