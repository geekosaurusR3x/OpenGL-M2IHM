##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=OpenGL_M2IHM
ConfigurationName      :=Debug
WorkspacePath          := "/home/skad/Projet"
ProjectPath            := "/home/skad/Projet/OpenGL-M2IHM"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=01/27/14
CodeLitePath           :="/home/skad/.codelite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
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
ObjectsFileList        :="OpenGL_M2IHM.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)GL $(LibrarySwitch)GLU $(LibrarySwitch)glut $(LibrarySwitch)jpeg 
ArLibs                 :=  "GL" "GLU" "glut" "libjpeg" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall -Wno-unused-variable -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall -Wno-unused-variable -std=c++11 $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/eolien$(ObjectSuffix) $(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/world$(ObjectSuffix) $(IntermediateDirectory)/fonctions$(ObjectSuffix) $(IntermediateDirectory)/jpeg_exception$(ObjectSuffix) $(IntermediateDirectory)/Couleur$(ObjectSuffix) $(IntermediateDirectory)/Fleche$(ObjectSuffix) $(IntermediateDirectory)/sky_box$(ObjectSuffix) $(IntermediateDirectory)/terran$(ObjectSuffix) $(IntermediateDirectory)/object$(ObjectSuffix) \
	$(IntermediateDirectory)/bug_droid$(ObjectSuffix) $(IntermediateDirectory)/water$(ObjectSuffix) $(IntermediateDirectory)/vector3d$(ObjectSuffix) $(IntermediateDirectory)/cam_free$(ObjectSuffix) $(IntermediateDirectory)/cam_rotate$(ObjectSuffix) $(IntermediateDirectory)/camera$(ObjectSuffix) $(IntermediateDirectory)/terminal$(ObjectSuffix) $(IntermediateDirectory)/loger$(ObjectSuffix) $(IntermediateDirectory)/Soleil$(ObjectSuffix) $(IntermediateDirectory)/Lumieres$(ObjectSuffix) \
	$(IntermediateDirectory)/Projecteur$(ObjectSuffix) 



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
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/eolien$(ObjectSuffix): eolien.cpp $(IntermediateDirectory)/eolien$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/skad/Projet/OpenGL-M2IHM/eolien.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/eolien$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/eolien$(DependSuffix): eolien.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/eolien$(ObjectSuffix) -MF$(IntermediateDirectory)/eolien$(DependSuffix) -MM "eolien.cpp"

$(IntermediateDirectory)/eolien$(PreprocessSuffix): eolien.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/eolien$(PreprocessSuffix) "eolien.cpp"

$(IntermediateDirectory)/main$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/skad/Projet/OpenGL-M2IHM/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/world$(ObjectSuffix): world.cpp $(IntermediateDirectory)/world$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/skad/Projet/OpenGL-M2IHM/world.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/world$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/world$(DependSuffix): world.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/world$(ObjectSuffix) -MF$(IntermediateDirectory)/world$(DependSuffix) -MM "world.cpp"

$(IntermediateDirectory)/world$(PreprocessSuffix): world.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/world$(PreprocessSuffix) "world.cpp"

$(IntermediateDirectory)/fonctions$(ObjectSuffix): fonctions.cpp $(IntermediateDirectory)/fonctions$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/skad/Projet/OpenGL-M2IHM/fonctions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/fonctions$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/fonctions$(DependSuffix): fonctions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/fonctions$(ObjectSuffix) -MF$(IntermediateDirectory)/fonctions$(DependSuffix) -MM "fonctions.cpp"

$(IntermediateDirectory)/fonctions$(PreprocessSuffix): fonctions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/fonctions$(PreprocessSuffix) "fonctions.cpp"

$(IntermediateDirectory)/jpeg_exception$(ObjectSuffix): jpeg_exception.cpp $(IntermediateDirectory)/jpeg_exception$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/skad/Projet/OpenGL-M2IHM/jpeg_exception.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/jpeg_exception$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/jpeg_exception$(DependSuffix): jpeg_exception.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/jpeg_exception$(ObjectSuffix) -MF$(IntermediateDirectory)/jpeg_exception$(DependSuffix) -MM "jpeg_exception.cpp"

$(IntermediateDirectory)/jpeg_exception$(PreprocessSuffix): jpeg_exception.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/jpeg_exception$(PreprocessSuffix) "jpeg_exception.cpp"

$(IntermediateDirectory)/Couleur$(ObjectSuffix): Couleur.cpp $(IntermediateDirectory)/Couleur$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/skad/Projet/OpenGL-M2IHM/Couleur.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Couleur$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Couleur$(DependSuffix): Couleur.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Couleur$(ObjectSuffix) -MF$(IntermediateDirectory)/Couleur$(DependSuffix) -MM "Couleur.cpp"

$(IntermediateDirectory)/Couleur$(PreprocessSuffix): Couleur.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Couleur$(PreprocessSuffix) "Couleur.cpp"

$(IntermediateDirectory)/Fleche$(ObjectSuffix): Fleche.cpp $(IntermediateDirectory)/Fleche$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/skad/Projet/OpenGL-M2IHM/Fleche.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Fleche$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Fleche$(DependSuffix): Fleche.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Fleche$(ObjectSuffix) -MF$(IntermediateDirectory)/Fleche$(DependSuffix) -MM "Fleche.cpp"

$(IntermediateDirectory)/Fleche$(PreprocessSuffix): Fleche.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Fleche$(PreprocessSuffix) "Fleche.cpp"

$(IntermediateDirectory)/sky_box$(ObjectSuffix): sky_box.cpp $(IntermediateDirectory)/sky_box$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/skad/Projet/OpenGL-M2IHM/sky_box.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sky_box$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sky_box$(DependSuffix): sky_box.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sky_box$(ObjectSuffix) -MF$(IntermediateDirectory)/sky_box$(DependSuffix) -MM "sky_box.cpp"

$(IntermediateDirectory)/sky_box$(PreprocessSuffix): sky_box.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sky_box$(PreprocessSuffix) "sky_box.cpp"

$(IntermediateDirectory)/terran$(ObjectSuffix): terran.cpp $(IntermediateDirectory)/terran$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/skad/Projet/OpenGL-M2IHM/terran.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/terran$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/terran$(DependSuffix): terran.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/terran$(ObjectSuffix) -MF$(IntermediateDirectory)/terran$(DependSuffix) -MM "terran.cpp"

$(IntermediateDirectory)/terran$(PreprocessSuffix): terran.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/terran$(PreprocessSuffix) "terran.cpp"

$(IntermediateDirectory)/object$(ObjectSuffix): object.cpp $(IntermediateDirectory)/object$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/skad/Projet/OpenGL-M2IHM/object.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/object$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/object$(DependSuffix): object.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/object$(ObjectSuffix) -MF$(IntermediateDirectory)/object$(DependSuffix) -MM "object.cpp"

$(IntermediateDirectory)/object$(PreprocessSuffix): object.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/object$(PreprocessSuffix) "object.cpp"

$(IntermediateDirectory)/bug_droid$(ObjectSuffix): bug_droid.cpp $(IntermediateDirectory)/bug_droid$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/skad/Projet/OpenGL-M2IHM/bug_droid.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bug_droid$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bug_droid$(DependSuffix): bug_droid.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bug_droid$(ObjectSuffix) -MF$(IntermediateDirectory)/bug_droid$(DependSuffix) -MM "bug_droid.cpp"

$(IntermediateDirectory)/bug_droid$(PreprocessSuffix): bug_droid.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bug_droid$(PreprocessSuffix) "bug_droid.cpp"

$(IntermediateDirectory)/water$(ObjectSuffix): water.cpp $(IntermediateDirectory)/water$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/skad/Projet/OpenGL-M2IHM/water.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/water$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/water$(DependSuffix): water.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/water$(ObjectSuffix) -MF$(IntermediateDirectory)/water$(DependSuffix) -MM "water.cpp"

$(IntermediateDirectory)/water$(PreprocessSuffix): water.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/water$(PreprocessSuffix) "water.cpp"

$(IntermediateDirectory)/vector3d$(ObjectSuffix): vector3d.cpp $(IntermediateDirectory)/vector3d$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/skad/Projet/OpenGL-M2IHM/vector3d.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vector3d$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vector3d$(DependSuffix): vector3d.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vector3d$(ObjectSuffix) -MF$(IntermediateDirectory)/vector3d$(DependSuffix) -MM "vector3d.cpp"

$(IntermediateDirectory)/vector3d$(PreprocessSuffix): vector3d.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vector3d$(PreprocessSuffix) "vector3d.cpp"

$(IntermediateDirectory)/cam_free$(ObjectSuffix): cam_free.cpp $(IntermediateDirectory)/cam_free$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/skad/Projet/OpenGL-M2IHM/cam_free.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cam_free$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cam_free$(DependSuffix): cam_free.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cam_free$(ObjectSuffix) -MF$(IntermediateDirectory)/cam_free$(DependSuffix) -MM "cam_free.cpp"

$(IntermediateDirectory)/cam_free$(PreprocessSuffix): cam_free.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cam_free$(PreprocessSuffix) "cam_free.cpp"

$(IntermediateDirectory)/cam_rotate$(ObjectSuffix): cam_rotate.cpp $(IntermediateDirectory)/cam_rotate$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/skad/Projet/OpenGL-M2IHM/cam_rotate.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cam_rotate$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cam_rotate$(DependSuffix): cam_rotate.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cam_rotate$(ObjectSuffix) -MF$(IntermediateDirectory)/cam_rotate$(DependSuffix) -MM "cam_rotate.cpp"

$(IntermediateDirectory)/cam_rotate$(PreprocessSuffix): cam_rotate.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cam_rotate$(PreprocessSuffix) "cam_rotate.cpp"

$(IntermediateDirectory)/camera$(ObjectSuffix): camera.cpp $(IntermediateDirectory)/camera$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/skad/Projet/OpenGL-M2IHM/camera.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/camera$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/camera$(DependSuffix): camera.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/camera$(ObjectSuffix) -MF$(IntermediateDirectory)/camera$(DependSuffix) -MM "camera.cpp"

$(IntermediateDirectory)/camera$(PreprocessSuffix): camera.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/camera$(PreprocessSuffix) "camera.cpp"

$(IntermediateDirectory)/terminal$(ObjectSuffix): terminal.cpp $(IntermediateDirectory)/terminal$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/skad/Projet/OpenGL-M2IHM/terminal.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/terminal$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/terminal$(DependSuffix): terminal.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/terminal$(ObjectSuffix) -MF$(IntermediateDirectory)/terminal$(DependSuffix) -MM "terminal.cpp"

$(IntermediateDirectory)/terminal$(PreprocessSuffix): terminal.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/terminal$(PreprocessSuffix) "terminal.cpp"

$(IntermediateDirectory)/loger$(ObjectSuffix): loger.cpp $(IntermediateDirectory)/loger$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/skad/Projet/OpenGL-M2IHM/loger.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/loger$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/loger$(DependSuffix): loger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/loger$(ObjectSuffix) -MF$(IntermediateDirectory)/loger$(DependSuffix) -MM "loger.cpp"

$(IntermediateDirectory)/loger$(PreprocessSuffix): loger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/loger$(PreprocessSuffix) "loger.cpp"

$(IntermediateDirectory)/Soleil$(ObjectSuffix): Soleil.cpp $(IntermediateDirectory)/Soleil$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/skad/Projet/OpenGL-M2IHM/Soleil.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Soleil$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Soleil$(DependSuffix): Soleil.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Soleil$(ObjectSuffix) -MF$(IntermediateDirectory)/Soleil$(DependSuffix) -MM "Soleil.cpp"

$(IntermediateDirectory)/Soleil$(PreprocessSuffix): Soleil.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Soleil$(PreprocessSuffix) "Soleil.cpp"

$(IntermediateDirectory)/Lumieres$(ObjectSuffix): Lumieres.cpp $(IntermediateDirectory)/Lumieres$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/skad/Projet/OpenGL-M2IHM/Lumieres.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lumieres$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Lumieres$(DependSuffix): Lumieres.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Lumieres$(ObjectSuffix) -MF$(IntermediateDirectory)/Lumieres$(DependSuffix) -MM "Lumieres.cpp"

$(IntermediateDirectory)/Lumieres$(PreprocessSuffix): Lumieres.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Lumieres$(PreprocessSuffix) "Lumieres.cpp"

$(IntermediateDirectory)/Projecteur$(ObjectSuffix): Projecteur.cpp $(IntermediateDirectory)/Projecteur$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/skad/Projet/OpenGL-M2IHM/Projecteur.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Projecteur$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Projecteur$(DependSuffix): Projecteur.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Projecteur$(ObjectSuffix) -MF$(IntermediateDirectory)/Projecteur$(DependSuffix) -MM "Projecteur.cpp"

$(IntermediateDirectory)/Projecteur$(PreprocessSuffix): Projecteur.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Projecteur$(PreprocessSuffix) "Projecteur.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/eolien$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/eolien$(DependSuffix)
	$(RM) $(IntermediateDirectory)/eolien$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/world$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/world$(DependSuffix)
	$(RM) $(IntermediateDirectory)/world$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/fonctions$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/fonctions$(DependSuffix)
	$(RM) $(IntermediateDirectory)/fonctions$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/jpeg_exception$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/jpeg_exception$(DependSuffix)
	$(RM) $(IntermediateDirectory)/jpeg_exception$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Couleur$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Couleur$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Couleur$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Fleche$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Fleche$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Fleche$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/sky_box$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/sky_box$(DependSuffix)
	$(RM) $(IntermediateDirectory)/sky_box$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/terran$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/terran$(DependSuffix)
	$(RM) $(IntermediateDirectory)/terran$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/object$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/object$(DependSuffix)
	$(RM) $(IntermediateDirectory)/object$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/bug_droid$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/bug_droid$(DependSuffix)
	$(RM) $(IntermediateDirectory)/bug_droid$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/water$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/water$(DependSuffix)
	$(RM) $(IntermediateDirectory)/water$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/vector3d$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/vector3d$(DependSuffix)
	$(RM) $(IntermediateDirectory)/vector3d$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/cam_free$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/cam_free$(DependSuffix)
	$(RM) $(IntermediateDirectory)/cam_free$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/cam_rotate$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/cam_rotate$(DependSuffix)
	$(RM) $(IntermediateDirectory)/cam_rotate$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/camera$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/camera$(DependSuffix)
	$(RM) $(IntermediateDirectory)/camera$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/terminal$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/terminal$(DependSuffix)
	$(RM) $(IntermediateDirectory)/terminal$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/loger$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/loger$(DependSuffix)
	$(RM) $(IntermediateDirectory)/loger$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Soleil$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Soleil$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Soleil$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Lumieres$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Lumieres$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Lumieres$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Projecteur$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Projecteur$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Projecteur$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) "../.build-debug/OpenGL_M2IHM"


