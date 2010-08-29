
-- Project ----------------------------------------------------------------------------------

project.name = "foursquarepp"
project.bindir = "build"

-- Package ----------------------------------------------------------------------------------

package = newpackage()

package.name = "foursquarepp"
package.kind = "dll"
package.language = "c++"
package.configs = { "Debug", "Release" }

if (windows) then
   table.insert(package.defines, "WIN32") -- Needed to fix something on Windows.
end

-- Include and library search paths, system dependent (I don't assume a directory structure)

package.includepaths = {
-- for more boost awesomeness
"./cpp-netlib/",
"./include",

-- alter this as required to point to a relatively recent 
-- version of boost (I've been testing against 1.44, but 1.42
-- might work as well)
"/usr/local/include/boost"

}

package.libpaths = {
"/usr/local/lib",
}

-- Libraries to link to ---------------------------------------------------------------------

package.links = {
"pthread",
"boost_system",
"boost_regex",
"boost_program_options",
"ssl",
}

-- pkg-configable stuff ---------------------------------------------------------------------

if (linux) then
package.buildoptions = {
"-Winvalid-pch"
}

package.linkoptions = {
}
end

-- Files ------------------------------------------------------------------------------------

package.files = {
"src/foursquare.cpp"
--matchrecursive("include/*.h", "./src/*.cpp"),
}

-- Debug configuration ----------------------------------------------------------------------

debug = package.config["Debug"]
debug.defines = { "DEBUG", "_DEBUG" }
debug.objdir = "obj/debug"
debug.target = "debug/" .. package.name .. "_d"

debug.buildoptions = { "-g" }

-- Release configuration --------------------------------------------------------------------

release = package.config["Release"]
release.objdir = "obj/release"
release.target = "release/" .. package.name
