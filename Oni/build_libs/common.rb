# common configuration variables and methods
# that end up being used in both Oni/ext/oni/extconf.rb and Oni/Rakefile
# can be placed in this file.



NAME = 'oni'



# === Platform-dependent build configuration variables

PLATFORM           = "linux64"
TARGET             = "Release"
NUMBER_OF_CORES    = 4

	# TODO: accept platform, target, and number of cores as Rake arguments
	# (maybe you actually want to figure out platform automatially)


# === this path is most likely not going to be under the root directory of the Ruby gem
OF_ROOT = "/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/"


# === these fils should be under the root directory of this Ruby gem
path_to_file = File.absolute_path(File.dirname(__FILE__))

COMMON_CONFIG = File.absolute_path(__FILE__)

GEM_ROOT = File.expand_path('../', path_to_file)

DYNAMIC_LIB_PATH = File.expand_path("./bin/libs/", GEM_ROOT)



# === the sketch MAY be under the root directory, but could be configured to lie elsewhere

# 'ext/oni/cpp/oF_Test'
# 	'./mySketch'
# 	'./mySketch/lib'

cpp_root = File.expand_path("ext/#{NAME}/cpp/", GEM_ROOT)
	
	# This way, you can set OF_SKETCH_ROOT to some other value before requiring this file,
	# and everything else will update to match.
	OF_SKETCH_ROOT = File.expand_path('mySketch/', cpp_root) unless defined? OF_SKETCH_ROOT
		
		OF_SKETCH_SRC_DIR         = File.expand_path('src', OF_SKETCH_ROOT)
		OF_SKETCH_SRC_FILES       = Dir.glob(File.join(OF_SKETCH_SRC_DIR, '*{.cpp,.h}'))
		
		OF_SKETCH_LIB_OUTPUT_PATH = File.expand_path('lib', OF_SKETCH_ROOT)
		OF_SKETCH_LIB_FILE = File.join(OF_SKETCH_LIB_OUTPUT_PATH, 'libOFSketch.a')
		
		
		OF_BUILD_VARIABLE_FILE = File.expand_path("./oF_build_variables.yaml", OF_SKETCH_ROOT)









# interactive command-line program execution
def run_i(cmd_string, &block)
	exit_status = nil
	Open3.popen2e(cmd_string) do |stdin, stdout_and_stderr, wait_thr|
		output = nil
		begin
			output = stdout_and_stderr.gets
			puts output
		end while output
		
		
		exit_status = wait_thr.value
	end
	
	if block
		# call the block if there is an error
		raise block.call if exit_status != 0
	end
	
	return exit_status
end





