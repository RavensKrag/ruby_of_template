require 'mkmf-rice'


dir_config(
	"OniBase",
	File.expand_path(".cpp/oF_Test/mySketch/"), # oF stuff
	File.expand_path("./cpp/lib/")              # C++ stuff
)

have_library('OFSketch')

create_makefile('oni')
