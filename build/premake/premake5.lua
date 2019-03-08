
--
-- If premake command is not supplied an action (target compiler), exit!
--
-- Targets of interest:
--     vs2017     Visual Studio 2017
--     gmake      Linux
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

   -- C++ code in all projects
   language "C++"

   --
   -- Build (solution) configuration options:
   --     Release        (Runtime library is Multi-threaded DLL)
   --     Debug          (Runtime library is Multi-threaded Debug DLL)
   --
   configurations { "Release", "Debug" }

   if (_ACTION == "gmake") then
      buildoptions { "-std=c++17" }
      links { "stdc++fs" }
   end

   -- common release configuration flags and symbols
   filter { "configurations:Release" }
      optimize "On"
      if (_ACTION ~= "gmake") then
         -- favor speed over size
         buildoptions { "/Ot" }
         defines { "WIN32", "NDEBUG" }
      end

   -- common debug configuration flags and symbols
   filter { "configurations:Debug" }
      symbols "On"
      if (_ACTION ~= "gmake") then
         defines { "WIN32", "_DEBUG" }
      end

-- describe
project "describe"
   files {
      "../../src/describe.cpp"
   }
   targetname "describe"

-- writer
project "writer"
   files {
      "../../src/writer.cpp"
   }
   targetname "writer"
