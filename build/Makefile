BUILD_DIR := ./
SOURCE_DIR := ../src
OUTPUT_FILE_NAME := final.elf

SOURCE_FILE_LIST := $(SOURCE_DIR)/Startup.c


INCLUDE_PATH_LIST :=  -I$(SOURCE_DIR)
INCLUDE_PATH_LIST +=  -I$(SOURCE_DIR)/01_Service
INCLUDE_PATH_LIST +=  -I$(SOURCE_DIR)/01_Service/OS
INCLUDE_PATH_LIST +=  -I$(SOURCE_DIR)/02_HAL
INCLUDE_PATH_LIST +=  -I$(SOURCE_DIR)/02_HAL/Motor
INCLUDE_PATH_LIST +=  -I$(SOURCE_DIR)/03_MCAL
INCLUDE_PATH_LIST +=  -I$(SOURCE_DIR)/03_MCAL/GPIO
INCLUDE_PATH_LIST +=  -I$(SOURCE_DIR)/03_MCAL/SysTick
INCLUDE_PATH_LIST +=  -I$(SOURCE_DIR)/02_HAL/LED

COMPILER := arm-none-eabi-gcc
COMPILER_FLAGS := -c  -g3 -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -std=c99  -Wall -O0
LINKER := arm-none-eabi-gcc
LINKER_SCRIPT := $(BUILD_DIR)/TM4C123GH6PMI_ls.ld
LINKER_FLAGS := -T $(LINKER_SCRIPT) -nostdlib -Wl,-Map=$(BUILD_DIR)final.map -o $(OUTPUT_FILE_NAME)

all: clean build Link dump symbolTable elfToHex elfToBin
	
clean:
	@echo "Cleaning ..."
	@rm -f  $(wildcard *.o) $(wildcard *.elf) $(wildcard *.hex) $(wildcard *.txt) $(wildcard *.map)

build: Startup.o Main.o GPIO.o LED.o SysTick.o OS.o Motor.o
	

Link: 
	@echo "Linking ..."
	@$(LINKER) $(LINKER_FLAGS) *.o -o ${OUTPUT_FILE_NAME}


Main.o : $(SOURCE_DIR)/Main.c
	@echo "Building $^ ..." 
	@$(COMPILER) $(COMPILER_FLAGS) $(INCLUDE_PATH_LIST) $^ -o $(BUILD_DIR)/$@

Startup.o : $(SOURCE_DIR)/Startup.c
	@echo "Building $^ ..." 
	@$(COMPILER) $(COMPILER_FLAGS) $(INCLUDE_PATH_LIST) $^ -o $(BUILD_DIR)/$@

SysTick.o : $(SOURCE_DIR)/03_MCAL/SysTick/SysTick.c
	@echo "Building $^ ..." 
	@$(COMPILER) $(COMPILER_FLAGS) $(INCLUDE_PATH_LIST) $^ -o $(BUILD_DIR)/$@
	
GPIO.o : $(SOURCE_DIR)/03_MCAL/GPIO/GPIO.c
	@echo "Building $^ ..." 
	@$(COMPILER) $(COMPILER_FLAGS) $(INCLUDE_PATH_LIST) $^ -o $(BUILD_DIR)/$@

LED.o : $(SOURCE_DIR)/02_HAL/LED/LED.c
	@echo "Building $^ ..." 
	@$(COMPILER) $(COMPILER_FLAGS) $(INCLUDE_PATH_LIST) $^ -o $(BUILD_DIR)/$@
	
Motor.o : $(SOURCE_DIR)/02_HAL/Motor/Motor.c
	@echo "Building $^ ..." 
	@$(COMPILER) $(COMPILER_FLAGS) $(INCLUDE_PATH_LIST) $^ -o $(BUILD_DIR)/$@
	
OS.o : $(SOURCE_DIR)/01_Service/OS/OS.c
	@echo "Building $^ ..." 
	@$(COMPILER) $(COMPILER_FLAGS) $(INCLUDE_PATH_LIST) $^ -o $(BUILD_DIR)/$@
	
dump :
	@echo "Dumping..."
	@arm-none-eabi-objdump -D $(OUTPUT_FILE_NAME) > finalDump.txt

symbolTable :
	@echo "symbolTable..."
	@arm-none-eabi-nm $(OUTPUT_FILE_NAME) > symbolTable.txt
	
elfToHex : $(BUILD_DIR)$(OUTPUT_FILE_NAME)
	@arm-none-eabi-objcopy -O ihex $^ $(BUILD_DIR)final.hex
	
elfToBin : $(BUILD_DIR)$(OUTPUT_FILE_NAME)
	@arm-none-eabi-objcopy -O binary $^ $(BUILD_DIR)final.bin
	
connect : $(BUILD_DIR)$(OUTPUT_FILE_NAME)
	@openocd -f ..\scripts\board\ek-tm4c123gxl.cfg