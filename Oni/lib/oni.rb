puts "load C code..."

# Stolen from Gosu's code to load the dynamic library
if defined? RUBY_PLATFORM and
%w(-win32 win32- mswin mingw32).any? { |s| RUBY_PLATFORM.include? s } then
	ENV['PATH'] = "#{File.dirname(__FILE__)};#{ENV['PATH']}"
end

require File.expand_path('oni/oni', File.absolute_path(File.dirname(__FILE__)))
puts "loading ruby code"

class Numeric
	def degrees
		# Assume that this is an angle in radians, and convert to degrees
		# This is so you can write 20.degrees instead of 20.to_deg
		self/ 180.0 * Math::PI
	end
end




module Oni


class Window
	def setup
		puts "ruby: Window#setup"
	end
	
	def update
		puts "ruby: Window#update"
	end
	
	def draw
		puts "ruby: Window#draw"
	end
	
	# NOTE: this method can not be called 'exit' because there is a method Kernel.exit
	def on_exit
		puts "ruby: exiting application..."
	end
	
	def mouse_moved(x,y)
		p [x,y]
	end
	
	def mouse_pressed(x,y, button)
		p [:pressed, x,y, button]
	end
	
	def mouse_released(x,y, button)
		p [:released, x,y, button]
	end
	
	def mouse_dragged(x,y, button)
		p [:dragged, x,y, button]
	end
	
	
	def mouse_entered(x,y)
		p [:mouse_in, x,y]
	end
	
	def mouse_exited(x,y)
		p [:mouse_out, x,y]
	end
	
	def window_resized(w,h)
		p [:resize, w,h]
	end
	
	def drag_event(files, position)
		p [files, position]
	end
	
	def got_message()
		# NOTE: not currently bound
	end
end


class Point
	def to_s
		format = '%.03f'
		x = format % self.x
		y = format % self.y
		z = format % self.z
		
		return "(#{x}, #{y}, #{z})"
	end
	
	def inspect
		super()
	end
	
	
	
	# hide C++ level helper methods
	private :get_component
	private :set_component
	
	
	# get / set value of a component by numerical index
	def [](i)
		return get_component(i)
	end
	
	def []=(i, value)
		return set_component(i, value.to_f)
	end
	
	
	# get / set values of component by axis name
	%w[x y z].each_with_index do |component, i|
		# getters
		# (same as array-style interface)
		define_method component do
			get_component(i)
		end 
		
		# setters
		# (use special C++ function to make sure data is written back to C++ land)
		define_method "#{component}=" do |value|
			set_component(i, value.to_f)
		end 
	end
end


# class Animation
# 	class Track
# 		def playing?
# 			return !ended?
# 		end
# 	end
# end
end
