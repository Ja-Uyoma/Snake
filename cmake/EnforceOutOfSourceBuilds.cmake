function(EnforceOutOfSourceBuilds)
    get_filename_component(srcDir "${CMAKE_SOURCE_DIR}" REALPATH)
    get_filename_component(binaryDir "${CMAKE_BINARY_DIR}" REALPATH)

    if("${srcDir}" STREQUAL "${binaryDir}")
        message("##################################################################")
        message("WARNING: In-source builds are not permitted!")
        message("Please create a separate build directory and run cmake from there.")
        message("##################################################################")
        message(FATAL_ERROR "Quitting configuration")
    endif("${srcDir}" STREQUAL "${binaryDir}")
    
endfunction(EnforceOutOfSourceBuilds)

EnforceOutOfSourceBuilds()
