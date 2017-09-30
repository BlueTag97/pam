TEST_SRC = main.c
TEST_EXE = get_pid_info

BASE_DIR = /usr/src/linux-4.14-rc1
KERNEL_DIR = $(BASE_DIR)/kernel
SYSCALLS_DIR = $(BASE_DIR)/arch/x86/entry/syscalls

SYS_C = $(KERNEL_DIR)/sys.c
SYS_TBL = $(SYSCALLS_DIR)/syscall_64.tbl

MY_C = sys.c
MY_TBL = syscall_64.tbl

all: $(TEST_EXE)

$(TEST_EXE): $(TEST_SRC)
	gcc -Wall -Werror -Wextra $< -o $@

clean:
	rm -f $(TEST_EXE)

update_kernel:
	rm -f $(SYS_C)
	rm -f $(SYS_TBL)
	cp $(MY_C) $(SYS_C)
	cp $(MY_TBL) $(SYS_TBL)
	make -j4 -C $(KERNEL_DIR)
	make modules_install -C $(KERNEL_DIR)

.PHONY: all clean update_kernel
