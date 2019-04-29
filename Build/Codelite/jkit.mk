##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=jkit
ConfigurationName      :=Debug
WorkspacePath          := "/home/lxndr/devel/research/jkit/Build/Codelite"
ProjectPath            := "/home/lxndr/devel/research/jkit/Build/Codelite"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alexander
Date                   :=01/01/15
CodeLitePath           :="/home/lxndr/.codelite"
LinkerName             :=/usr/bin/g++ 
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName).so
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="jkit.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)$(ProjectPath)/../.. 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++ 
CC       := /usr/bin/gcc 
CXXFLAGS :=  -g -std=c++11 -Wall -fPIC $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/Core_Application.cpp$(ObjectSuffix) $(IntermediateDirectory)/Core_Exception.cpp$(ObjectSuffix) $(IntermediateDirectory)/Core_FileStream.cpp$(ObjectSuffix) $(IntermediateDirectory)/Core_MemoryStream.cpp$(ObjectSuffix) $(IntermediateDirectory)/Core_Object.cpp$(ObjectSuffix) $(IntermediateDirectory)/Core_ObjectProperty.cpp$(ObjectSuffix) $(IntermediateDirectory)/Core_Stream.cpp$(ObjectSuffix) $(IntermediateDirectory)/Core_String.cpp$(ObjectSuffix) $(IntermediateDirectory)/Posix_Exception.cpp$(ObjectSuffix) $(IntermediateDirectory)/Posix_FileStream.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Posix_LocalFile.cpp$(ObjectSuffix) $(IntermediateDirectory)/Windows_Utils.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)
	@$(MakeDirCommand) "/home/lxndr/devel/research/jkit/Build/Codelite/.build-debug"
	@echo rebuilt > "/home/lxndr/devel/research/jkit/Build/Codelite/.build-debug/jkit"

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Core_Application.cpp$(ObjectSuffix): ../../JKit/Core/Application.cpp $(IntermediateDirectory)/Core_Application.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lxndr/devel/research/jkit/JKit/Core/Application.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Core_Application.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Core_Application.cpp$(DependSuffix): ../../JKit/Core/Application.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Core_Application.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Core_Application.cpp$(DependSuffix) -MM "../../JKit/Core/Application.cpp"

$(IntermediateDirectory)/Core_Application.cpp$(PreprocessSuffix): ../../JKit/Core/Application.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Core_Application.cpp$(PreprocessSuffix) "../../JKit/Core/Application.cpp"

$(IntermediateDirectory)/Core_Exception.cpp$(ObjectSuffix): ../../JKit/Core/Exception.cpp $(IntermediateDirectory)/Core_Exception.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lxndr/devel/research/jkit/JKit/Core/Exception.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Core_Exception.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Core_Exception.cpp$(DependSuffix): ../../JKit/Core/Exception.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Core_Exception.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Core_Exception.cpp$(DependSuffix) -MM "../../JKit/Core/Exception.cpp"

$(IntermediateDirectory)/Core_Exception.cpp$(PreprocessSuffix): ../../JKit/Core/Exception.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Core_Exception.cpp$(PreprocessSuffix) "../../JKit/Core/Exception.cpp"

$(IntermediateDirectory)/Core_FileStream.cpp$(ObjectSuffix): ../../JKit/Core/FileStream.cpp $(IntermediateDirectory)/Core_FileStream.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lxndr/devel/research/jkit/JKit/Core/FileStream.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Core_FileStream.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Core_FileStream.cpp$(DependSuffix): ../../JKit/Core/FileStream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Core_FileStream.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Core_FileStream.cpp$(DependSuffix) -MM "../../JKit/Core/FileStream.cpp"

$(IntermediateDirectory)/Core_FileStream.cpp$(PreprocessSuffix): ../../JKit/Core/FileStream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Core_FileStream.cpp$(PreprocessSuffix) "../../JKit/Core/FileStream.cpp"

$(IntermediateDirectory)/Core_MemoryStream.cpp$(ObjectSuffix): ../../JKit/Core/MemoryStream.cpp $(IntermediateDirectory)/Core_MemoryStream.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lxndr/devel/research/jkit/JKit/Core/MemoryStream.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Core_MemoryStream.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Core_MemoryStream.cpp$(DependSuffix): ../../JKit/Core/MemoryStream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Core_MemoryStream.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Core_MemoryStream.cpp$(DependSuffix) -MM "../../JKit/Core/MemoryStream.cpp"

$(IntermediateDirectory)/Core_MemoryStream.cpp$(PreprocessSuffix): ../../JKit/Core/MemoryStream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Core_MemoryStream.cpp$(PreprocessSuffix) "../../JKit/Core/MemoryStream.cpp"

$(IntermediateDirectory)/Core_Object.cpp$(ObjectSuffix): ../../JKit/Core/Object.cpp $(IntermediateDirectory)/Core_Object.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lxndr/devel/research/jkit/JKit/Core/Object.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Core_Object.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Core_Object.cpp$(DependSuffix): ../../JKit/Core/Object.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Core_Object.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Core_Object.cpp$(DependSuffix) -MM "../../JKit/Core/Object.cpp"

$(IntermediateDirectory)/Core_Object.cpp$(PreprocessSuffix): ../../JKit/Core/Object.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Core_Object.cpp$(PreprocessSuffix) "../../JKit/Core/Object.cpp"

$(IntermediateDirectory)/Core_ObjectProperty.cpp$(ObjectSuffix): ../../JKit/Core/ObjectProperty.cpp $(IntermediateDirectory)/Core_ObjectProperty.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lxndr/devel/research/jkit/JKit/Core/ObjectProperty.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Core_ObjectProperty.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Core_ObjectProperty.cpp$(DependSuffix): ../../JKit/Core/ObjectProperty.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Core_ObjectProperty.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Core_ObjectProperty.cpp$(DependSuffix) -MM "../../JKit/Core/ObjectProperty.cpp"

$(IntermediateDirectory)/Core_ObjectProperty.cpp$(PreprocessSuffix): ../../JKit/Core/ObjectProperty.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Core_ObjectProperty.cpp$(PreprocessSuffix) "../../JKit/Core/ObjectProperty.cpp"

$(IntermediateDirectory)/Core_Stream.cpp$(ObjectSuffix): ../../JKit/Core/Stream.cpp $(IntermediateDirectory)/Core_Stream.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lxndr/devel/research/jkit/JKit/Core/Stream.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Core_Stream.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Core_Stream.cpp$(DependSuffix): ../../JKit/Core/Stream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Core_Stream.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Core_Stream.cpp$(DependSuffix) -MM "../../JKit/Core/Stream.cpp"

$(IntermediateDirectory)/Core_Stream.cpp$(PreprocessSuffix): ../../JKit/Core/Stream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Core_Stream.cpp$(PreprocessSuffix) "../../JKit/Core/Stream.cpp"

$(IntermediateDirectory)/Core_String.cpp$(ObjectSuffix): ../../JKit/Core/String.cpp $(IntermediateDirectory)/Core_String.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lxndr/devel/research/jkit/JKit/Core/String.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Core_String.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Core_String.cpp$(DependSuffix): ../../JKit/Core/String.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Core_String.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Core_String.cpp$(DependSuffix) -MM "../../JKit/Core/String.cpp"

$(IntermediateDirectory)/Core_String.cpp$(PreprocessSuffix): ../../JKit/Core/String.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Core_String.cpp$(PreprocessSuffix) "../../JKit/Core/String.cpp"

$(IntermediateDirectory)/Posix_Exception.cpp$(ObjectSuffix): ../../JKit/Core/Detail/Posix/Exception.cpp $(IntermediateDirectory)/Posix_Exception.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lxndr/devel/research/jkit/JKit/Core/Detail/Posix/Exception.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Posix_Exception.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Posix_Exception.cpp$(DependSuffix): ../../JKit/Core/Detail/Posix/Exception.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Posix_Exception.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Posix_Exception.cpp$(DependSuffix) -MM "../../JKit/Core/Detail/Posix/Exception.cpp"

$(IntermediateDirectory)/Posix_Exception.cpp$(PreprocessSuffix): ../../JKit/Core/Detail/Posix/Exception.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Posix_Exception.cpp$(PreprocessSuffix) "../../JKit/Core/Detail/Posix/Exception.cpp"

$(IntermediateDirectory)/Posix_FileStream.cpp$(ObjectSuffix): ../../JKit/Core/Detail/Posix/FileStream.cpp $(IntermediateDirectory)/Posix_FileStream.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lxndr/devel/research/jkit/JKit/Core/Detail/Posix/FileStream.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Posix_FileStream.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Posix_FileStream.cpp$(DependSuffix): ../../JKit/Core/Detail/Posix/FileStream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Posix_FileStream.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Posix_FileStream.cpp$(DependSuffix) -MM "../../JKit/Core/Detail/Posix/FileStream.cpp"

$(IntermediateDirectory)/Posix_FileStream.cpp$(PreprocessSuffix): ../../JKit/Core/Detail/Posix/FileStream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Posix_FileStream.cpp$(PreprocessSuffix) "../../JKit/Core/Detail/Posix/FileStream.cpp"

$(IntermediateDirectory)/Posix_LocalFile.cpp$(ObjectSuffix): ../../JKit/Core/Detail/Posix/LocalFile.cpp $(IntermediateDirectory)/Posix_LocalFile.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lxndr/devel/research/jkit/JKit/Core/Detail/Posix/LocalFile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Posix_LocalFile.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Posix_LocalFile.cpp$(DependSuffix): ../../JKit/Core/Detail/Posix/LocalFile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Posix_LocalFile.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Posix_LocalFile.cpp$(DependSuffix) -MM "../../JKit/Core/Detail/Posix/LocalFile.cpp"

$(IntermediateDirectory)/Posix_LocalFile.cpp$(PreprocessSuffix): ../../JKit/Core/Detail/Posix/LocalFile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Posix_LocalFile.cpp$(PreprocessSuffix) "../../JKit/Core/Detail/Posix/LocalFile.cpp"

$(IntermediateDirectory)/Windows_Utils.cpp$(ObjectSuffix): ../../JKit/Core/Detail/Windows/Utils.cpp $(IntermediateDirectory)/Windows_Utils.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lxndr/devel/research/jkit/JKit/Core/Detail/Windows/Utils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Windows_Utils.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Windows_Utils.cpp$(DependSuffix): ../../JKit/Core/Detail/Windows/Utils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Windows_Utils.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Windows_Utils.cpp$(DependSuffix) -MM "../../JKit/Core/Detail/Windows/Utils.cpp"

$(IntermediateDirectory)/Windows_Utils.cpp$(PreprocessSuffix): ../../JKit/Core/Detail/Windows/Utils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Windows_Utils.cpp$(PreprocessSuffix) "../../JKit/Core/Detail/Windows/Utils.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) ".build-debug/jkit"


