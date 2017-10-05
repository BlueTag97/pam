LINUX_ROOT = /usr/src/linux-4.14-rc1
SYSCALL = get_pid_info
K_FILES = kernel_files

all: setup-files update-src compile-image update-image restart

setup-files:
	rm -f $(LINUX_ROOT)/include/linux/$(SYSCALL).h
	rm -f $(LINUX_ROOT)/Makefile
	rm -f $(LINUX_ROOT)/arch/x86/entry/syscalls/syscall_64.tbl 
	rm -f $(LINUX_ROOT)/include/linux/syscalls.h
	cp $(SYSCALL)/$(SYSCALL).h $(LINUX_ROOT)/include/linux/$(SYSCALL).h
	cp $(K_FILES)/Makefile $(LINUX_ROOT)/Makefile
	cp $(K_FILES)/syscall_64.tbl \
	$(LINUX_ROOT)/arch/x86/entry/syscalls/syscall_64.tbl 
	cp $(K_FILES)/syscalls.h $(LINUX_ROOT)/include/linux/syscalls.h

update-src:
	rm -rf $(LINUX_ROOT)/$(SYSCALL)
	cp -r $(SYSCALL) $(LINUX_ROOT)/$(SYSCALL)

compile-image:
	make -C $(LINUX_ROOT) -j4

update-image:
	rm -f /boot/System.map-4.14-emmmhla
	rm -f /boot/vmlinuz-4.14-emmmhla
	cp $(LINUX_ROOT)/System.map /boot/System.map-4.14-emmmhla
	cp $(LINUX_ROOT)/arch/x86/boot/bzImage /boot/vmlinuz-4.14-emmmhla

restart:
	shutdown -r now

.PHONY: all setup-files update-src compile-image update-image restart
