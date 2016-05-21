# TODO: use name of this file as name of package

require File.expand_path("../lib/oni/version", __FILE__)

ENABLE_C_EXTENSION = true
NAME = "oni"

Gem::Specification.new do |s|
	s.name        = NAME
	s.version     = Oni::VERSION
	
	# s.date        = '2013-01-17'
	# Use the current date
	d = Time.now
	s.date        = "#{d.year}-#{"%02d" % d.month}-#{"%02d" % d.day}"
	
	s.platform    = "x86-mingw32"
	s.authors     = ["Raven"]
	s.email       = 'AvantFlux.Raven@gmail.com'
	s.homepage    = 'https://github.com/RavensKrag'
	
	s.summary     = "3D game rendering framework built on the Ogre3D rendering engine"
	s.description = <<EOS
	Oni attempts to build a simple Ruby interface around commonly used Ogre3D rendering
	capabilities, as well as providing input and sound. It is intended to be used in
	conjunction with other C/C++ libraries, as well as Ruby libraries.
EOS

	s.required_rubygems_version = ">= 1.3.6"
	
	# lol - required for validation
	#~ s.rubyforge_project         = "newgem"
	
	# If you have other dependencies, add them here
	# s.add_dependency "another", "~> 1.2"
	
	s.files = Dir["{lib}/**/*.rb", "bin/*", "LICENSE", "*.md"]
	
	if ENABLE_C_EXTENSION
		# Ruby files
		s.files      += Dir["{ext}/#{NAME}/*.{rb}"]
		
		# WINDOWS ONLY
		# TODO: REMOVE WHEN CMAKE DEPENDECY IS REMOVED
		s.files      += Dir["{ext}/#{NAME}/cpp/lib/*.a"]
		s.files      += Dir["{lib}/#{NAME}/*.so"]
		s.files      += Dir["{lib}/*.dll"]

		# Licensing
		s.files      += Dir["legal/*.{txt}"]
	else
		
	end
	puts s.files
	
	s.require_path = 'lib'
	
	# If you need an executable, add it here
	# s.executables = ["newgem"]
	
	
	#~ s.autorequire = "name"
	s.test_files = Dir["{test}/**/*test.rb"]
	s.has_rdoc = true
	#~ s.extra_rdoc_files = ["README"]
	#~ s.add_dependency("dependency", ">= 0.x.x")
end
