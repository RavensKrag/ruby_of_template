require 'rake/testtask'
require 'rake/clean'
require 'open3'

# generate depend file for gcc dependencies
# sh "gcc -MM *.c > depend"

NAME = 'oni'

# the same as before
Rake::TestTask.new do |t|
	# t.test_files = []
	
	# t.libs << 'test'
	# t.test_files = FileList['test/test*.rb']
	
	# t.test_files = ["test/test_window_creation.rb"]
	
	# t.test_files = ["test/test_camera.rb"]
	
	# t.test_files = ["test/test_quad_creation.rb"]
	# t.test_files = ["test/test_keyboard_input.rb"]
	
	t.test_files = ["test/test_node_creation.rb"]
	
	# t.test_files = ["test/test_agent_creation.rb"]
	# t.test_files = ["test/test_agent_translation.rb"]
	# t.test_files = ["test/test_agent_rotation.rb"]
	# t.test_files = ["test/test_agent_scale.rb"]
	
	# t.test_files = ["test/test_lighting.rb"]
	
	# t.test_files = ["test/test_animation_benchmark.rb"]
	# t.test_files = ["test/test_animation_time.rb"]
	
	# t.test_files = ["test/test_set_animation.rb"]
	# t.test_files = ["test/test_get_animation.rb"]
	
	# t.test_files = ["test/test_attach_to_bone.rb"]
	# t.test_files = ["test/test_get_position_delta.rb"]
end



# make the :test task depend on the shared
# object, so it will be built automatically
# before running the tests

# rule to build the extension: this says
# that the extension should be rebuilt
# after any change to the files in ext

c_library = "lib/#{NAME}/#{NAME}.so"

source_files = Array.new
source_files += Dir.glob("ext/#{NAME}/*{.rb,.c}")
source_files += ["ext/#{NAME}/extconf.rb"]

source_files += Dir.glob("ext/#{NAME}/cpp/cpp_core/*{.cpp,.h}")
source_files += Dir.glob("ext/#{NAME}/cpp/cpp_interface/*{.cpp,.h}")

file c_library => source_files do
	Dir.chdir("ext/#{NAME}") do
		# this does essentially the same thing
		# as what RubyGems does
		ruby "extconf.rb"
		
		# Run make
		flags = ""
		stdin, stdout_and_stderr, wait_thr = Open3.popen2e "make " + flags
		
		output = nil
		begin
			output = stdout_and_stderr.gets
			puts output
		end while output
		
		stdin.close
		stdout_and_stderr.close
	end
	
	cp "ext/#{NAME}/#{NAME}.so", "lib/#{NAME}"
end

task :test => c_library

task :package => c_library do
	`gem build oni.gemspec`
end


# use 'rake clean' and 'rake clobber' to
# easily delete generated files
CLEAN.include('ext/**/*{.o,.log,.so}')
# CLEAN.include('ext/**/Makefile')
CLOBBER.include('lib/**/*.so')

desc "Run tests"
task :default => [:test, :package]

namespace :windows do
	task :package => :default do
		`gem build oni_win_precompiled.gemspec`		
	end
	
	task :release => Rake::Task['windows:package'] do
		
	end
end