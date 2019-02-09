
# Define an option to enable/disable this module.
#
# Though not actually required we guard each module 'moduleName' with
# a OSPRAY_MODULE_MODULENAME flag that enables/disables its building.
#
OPTION(OSPRAY_MODULE_RENDERER_VI2 "Build rendererVI2" ON)
IF (OSPRAY_MODULE_RENDERER_VI2)

  # build the actual module
  #
  # This subdirectory will eventually build the
  # libospray_module_<moduleName>.so library 
  #
  ADD_SUBDIRECTORY(render)


ENDIF (OSPRAY_MODULE_RENDERER_VI2)