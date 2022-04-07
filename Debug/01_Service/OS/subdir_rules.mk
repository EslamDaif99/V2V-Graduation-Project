################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
01_Service/OS/%.obj: ../01_Service/OS/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1110/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/Projects/Customer/V2V GP/Construction/Repo/V2V-Graduation-Project" --include_path="D:/Projects/Customer/V2V GP/Construction/Repo/V2V-Graduation-Project/02_HAL/LED" --include_path="D:/Projects/Customer/V2V GP/Construction/Repo/V2V-Graduation-Project/03_MCAL/GPIO" --include_path="D:/Projects/Customer/V2V GP/Construction/Repo/V2V-Graduation-Project/03_MCAL/SysTick" --include_path="D:/Projects/Customer/V2V GP/Construction/Repo/V2V-Graduation-Project/01_Service/OS" --include_path="D:/Projects/Customer/V2V GP/Construction/Repo/V2V-Graduation-Project/03_MCAL" --include_path="D:/Projects/Customer/V2V GP/Construction/Repo/V2V-Graduation-Project/04_Drivers/PWM" --include_path="D:/Projects/Customer/V2V GP/Construction/Repo/V2V-Graduation-Project/03_MCAL/UART" --include_path="D:/Projects/Customer/V2V GP/Construction/Repo/V2V-Graduation-Project/02_HAL/Motor" --include_path="C:/ti/ccs1110/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="01_Service/OS/$(basename $(<F)).d_raw" --obj_directory="01_Service/OS" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


