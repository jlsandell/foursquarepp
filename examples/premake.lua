
-- Project ----------------------------------------------------------------------------------

project.name = "examples"
project.bindir = "."

-- Package ----------------------------------------------------------------------------------

example_checkin = newpackage()

example_checkin.name = "example_checkin"
example_checkin.kind = "exe"
example_checkin.language = "c++"
example_checkin.configs = { "Debug", "Release" }

if (windows) then
   table.insert(example_checkin.defines, "WIN32") -- Needed to fix something on Windows.
end

-- Include and library search paths, system dependent (I don't assume a directory structure)

example_checkin.includepaths = {
-- for more boost awesomeness
"../cpp-netlib/",
"../include",

-- alter this as required to point to a relatively recent 
-- version of boost (I've been testing against 1.44, but 1.42
-- might work as well)
"/usr/local/include/boost"

}

example_checkin.libpaths = {
"/usr/local/lib",
"../build/debug"
}

-- Libraries to link to ---------------------------------------------------------------------

example_checkin.links = {
"pthread",
"boost_system",
"boost_regex",
"boost_program_options",
"ssl",
"foursquarepp_d"

}

-- pkg-configable stuff ---------------------------------------------------------------------

if (linux) then
example_checkin.buildoptions = {
}

example_checkin.linkoptions = {
}
end

-- Files ------------------------------------------------------------------------------------

example_checkin.files = {
"./example_checkin.cpp",
}


example_getcheckins = newpackage()

example_getcheckins.name = "example_getcheckins"
example_getcheckins.kind = "exe"
example_getcheckins.language = "c++"
example_getcheckins.configs = { "Debug", "Release" }

if (windows) then
   table.insert(example_getcheckins.defines, "WIN32") -- Needed to fix something on Windows.
end

-- Include and library search paths, system dependent (I don't assume a directory structure)

example_getcheckins.includepaths = {
-- for more boost awesomeness
"../cpp-netlib/",
"../include",

-- alter this as required to point to a relatively recent 
-- version of boost (I've been testing against 1.44, but 1.42
-- might work as well)
"/usr/local/include/boost"

}

example_getcheckins.libpaths = {
"/usr/local/lib",
"../build/debug"
}

-- Libraries to link to ---------------------------------------------------------------------

example_getcheckins.links = {
"pthread",
"boost_system",
"boost_regex",
"boost_program_options",
"ssl",
"foursquarepp_d"

}

-- pkg-configable stuff ---------------------------------------------------------------------

if (linux) then
example_getcheckins.buildoptions = {
}

example_getcheckins.linkoptions = {
}
end

-- Files ------------------------------------------------------------------------------------

example_getcheckins.files = {
"./example_getcheckins.cpp",
}




-- Debug configuration ----------------------------------------------------------------------

--debug = example_client.config["Debug"]
--debug.defines = { "DEBUG", "_DEBUG" }
--debug.objdir = "obj/debug"
--debug.target = "./" .. example_client.name .. "_d"

--debug.buildoptions = { "-g" }

-- Release configuration --------------------------------------------------------------------

--release = example_client.config["Release"]
--release.objdir = "obj/release"
--release.target = "release/" .. example_client.name
