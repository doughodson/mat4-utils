
--
-- If premake command is not supplied an action (target compiler), exit!
--
-- Targets of interest:
--     vs2017     (Visual Studio 2017)
--
if (_ACTION == nil) then
    return
end

workspace "mat4-utils"

   -- destination directory for generated solution/project files
   location ("../" .. _ACTION)
   -- destination directory for generated executable binary
   targetdir "../../bin"

   kind "ConsoleApp"

   -- C code in all projects
   language "C"

   --
   -- Build (solution) configuration options:
   --     Release        (Runtime library is Multi-threaded DLL)
   --     Debug          (Runtime library is Multi-threaded Debug DLL)
   --
   configurations { "Release", "Debug" }

   -- common release configuration flags and symbols
   filter { "configurations:Release" }
      optimize "On"
      -- favor speed over size
      buildoptions { "/Ot" }
      defines { "WIN32", "NDEBUG" }

   -- common debug configuration flags and symbols
   filter { "configurations:Debug" }
      symbols "On"
      -- enable compiler intrinsics
      defines { "WIN32", "_DEBUG" }

   -- describe
   project "describe"
      files {
         "../../src/describe.c"
      }
      targetname "describe"
