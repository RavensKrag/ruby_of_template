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
	
	
	
	private
	
	# Basic Graphics API
	
	private :ofBackground #(r, g, b, a)
	private :ofBackgroundHex #(hexColor, alpha)
	
	private :ofSetColor #(r, g, b, a)
	private :ofSetHexColor #(hexColor)
	
	
	private :ofDrawRectangle #(x,y,z,w,h)
	private :ofDrawCircle #(x, y, z, radius)
	private :ofDrawEllipse #(x, y, z, width, height)
	private :ofDrawTriangle #(x1,y1,z1,x2,y2,z2,x3, y3,z3)
	private :ofDrawLine #(x1,y1,z1,x2,y2,z2)
end


class Point
	def to_s
		super()
	end
	
	def inspect
		super()
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
