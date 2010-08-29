
-- Project ----------------------------------------------------------------------------------

project.name = "foursquarepp"
project.bindir = "build"

-- Package ----------------------------------------------------------------------------------

foursquarepp = newpackage()

foursquarepp.name = "foursquarepp"
foursquarepp.kind = "dll"
foursquarepp.language = "c++"
foursquarepp.configs = { "Debug", "Release" }

if (windows) then
   table.insert(foursquarepp.defines, "WIN32") -- Needed to fix something on Windows.
end

-- Include and library search paths, system dependent (I don't assume a directory structure)

foursquarepp.includepaths = {
-- for more boost awesomeness
"./cpp-netlib/",
"./include",

-- alter this as required to point to a relatively recent 
-- version of boost (I've been testing against 1.44, but 1.42
-- might work as well)
"/usr/local/include/boost"

}

foursquarepp.libpaths = {
"/usr/local/lib",
}

-- Libraries to link to ---------------------------------------------------------------------

foursquarepp.links = {
"pthread",
"boost_system",
"boost_regex",
"boost_program_options",
"ssl",
}

-- pkg-configable stuff ---------------------------------------------------------------------

if (linux) then
foursquarepp.buildoptions = {
"-fpch-preprocess",
"-Winvalid-pch",
}

foursquarepp.linkoptions = {
}
end

-- Files ------------------------------------------------------------------------------------

foursquarepp.files = {
"src/foursquare.cpp"
}

-- Debug configuration ----------------------------------------------------------------------

debug = foursquarepp.config["Debug"]
debug.defines = { "DEBUG", "_DEBUG" }
debug.objdir = "obj/debug"
debug.target = "debug/" .. foursquarepp.name .. "_d"

debug.buildoptions = { "-g" }

-- Release configuration --------------------------------------------------------------------

release = foursquarepp.config["Release"]
release.objdir = "obj/release"
release.target = "release/" .. foursquarepp.name
