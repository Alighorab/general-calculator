##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=calculator
ConfigurationName      :=Debug
WorkspacePath          :="E:/Study/Computer Science/C/Examples/simpletron-master/simpletron"
ProjectPath            :="E:/Study/Computer Science/C/Examples/Data Stuctures/Walled yousef/Stack/Application/Calculator/calculator"
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=aligh
Date                   :=07/11/2020
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=c:/users/aligh/gcc/bin/g++.exe
SharedObjectLinkerName :=c:/users/aligh/gcc/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="calculator.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=c:/users/aligh/gcc/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := c:/users/aligh/gcc/bin/ar.exe rcu
CXX      := c:/users/aligh/gcc/bin/g++.exe
CC       := c:/users/aligh/gcc/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := c:/users/aligh/gcc/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/postfix_evaluator.c$(ObjectSuffix) $(IntermediateDirectory)/infix_to_postfix.c$(ObjectSuffix) $(IntermediateDirectory)/stack.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(ConfigurationName)"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(ConfigurationName)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c
	$(CC) $(SourceSwitch) "E:/Study/Computer Science/C/Examples/Data Stuctures/Walled yousef/Stack/Application/Calculator/calculator/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/postfix_evaluator.c$(ObjectSuffix): postfix_evaluator.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/postfix_evaluator.c$(ObjectSuffix) -MF$(IntermediateDirectory)/postfix_evaluator.c$(DependSuffix) -MM postfix_evaluator.c
	$(CC) $(SourceSwitch) "E:/Study/Computer Science/C/Examples/Data Stuctures/Walled yousef/Stack/Application/Calculator/calculator/postfix_evaluator.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/postfix_evaluator.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/postfix_evaluator.c$(PreprocessSuffix): postfix_evaluator.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/postfix_evaluator.c$(PreprocessSuffix) postfix_evaluator.c

$(IntermediateDirectory)/infix_to_postfix.c$(ObjectSuffix): infix_to_postfix.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/infix_to_postfix.c$(ObjectSuffix) -MF$(IntermediateDirectory)/infix_to_postfix.c$(DependSuffix) -MM infix_to_postfix.c
	$(CC) $(SourceSwitch) "E:/Study/Computer Science/C/Examples/Data Stuctures/Walled yousef/Stack/Application/Calculator/calculator/infix_to_postfix.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/infix_to_postfix.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/infix_to_postfix.c$(PreprocessSuffix): infix_to_postfix.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/infix_to_postfix.c$(PreprocessSuffix) infix_to_postfix.c

$(IntermediateDirectory)/stack.c$(ObjectSuffix): stack.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/stack.c$(ObjectSuffix) -MF$(IntermediateDirectory)/stack.c$(DependSuffix) -MM stack.c
	$(CC) $(SourceSwitch) "E:/Study/Computer Science/C/Examples/Data Stuctures/Walled yousef/Stack/Application/Calculator/calculator/stack.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/stack.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/stack.c$(PreprocessSuffix): stack.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/stack.c$(PreprocessSuffix) stack.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


