TEMPLATEROOT = ..

# compilation flags for gdb

CFLAGS  = -O1 -g
ASFLAGS = -g 

# object files

OBJS=  $(STARTUP) main.o
OBJS+=stm32f10x_rcc.o stm32f10x_gpio.o lcd.o c2b.o

# include common make file

include $(TEMPLATEROOT)/Makefile.common

