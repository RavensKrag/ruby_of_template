root = File.expand_path('../../../', File.absolute_path(File.dirname(__FILE__)))
require File.expand_path('lib/oni', root)


# TODO: rename things so this project doesn't have symbol collision with the other package I named "Oni", from which this project's template derives.
	
# TODO: wrap functions to get window dimensions
# TODO: consider marking all drawing methods as private from Ruby-land

# TODO: when Ruby code throws an exception, supress the exception, trigger proper C++ shutdown, and then throw the exception again. Otherwise, you get segfaults, leaking, etc.


# TODO: wrap basic texture mapping features
# TODO: LATER use use of the batching sprite rendering extensions, wrapping that in Ruby, to draw images
# TODO: wrap batching draw call API so you don't have to lean so hard to the immediate mode stuff

class Window < Oni::Window
	include Oni::Graphics
	
	def initialize
		super("Test App")
		# ofSetEscapeQuitsApp false
		
		
		puts "ruby: Window#initialize"
		
		
		@p = [0,0]
		
		@p_history = Array.new
		@trail_dt = 1
		
		
		@font = Oni::TrueTypeFont.new
		load_status = @font.load("DejaVu Sans", 20)
		puts "Font loaded?: #{load_status}"
		
		
		@texture = Oni::Texture.new
		ofLoadImage(@texture, "/home/ravenskrag/Pictures/Buddy Icons/100shinn1.png")
	end
	
	def setup
		super()
	end
	
	def update
		# super()
		
		@tick ||= 0
		@tick += 1
		if @tick == @trail_dt
			@tick = 0
			
			@p_history << @p
		end
		
		trail_length = 20*3*2
		# if @tick == 30
		# 	@p_history.shift
		# end
		
		if @p_history.length > trail_length
			i = [0, @p_history.length - trail_length - 1].max
			@p_history.shift(i)
		end
		
		# p @p_history
	end
	
	def draw
		# super()
		
		# NOTE: background color should be set from C++ level, because C++ level code executes first. May consider flipping the order, or even defining TWO callbacks to Ruby.
		# ofBackground(171, 160, 228,   255) # rgba
		
		z = 1
		
		ofSetColor(171, 160, 228, 255) # rgba
		
		start = [12, 15]
		row_spacing = 15
		
		[
			"mouse: #{@p.inspect}",
			"window size: #{window_size.to_s}",
			"dt: #{ofGetLastFrameTime.round(5)}",
			"fps: #{ofGetFrameRate.round(5)}"
		].each_with_index do |string, i|
			x,y = start
			y += i*row_spacing
			
			ofDrawBitmapString(string, x,y,z)
		end
		
		
		ofSetColor(255, 255, 255, 255) # rgba
		
		
		ofDrawBitmapString("hello again from ruby!", 300, 350, z);
		ofDrawBitmapString("clipboard: #{self.clipboard_string.inspect}", 100, 400, z);
		# ^ NOTE: I think this gives you an error when the contains something that is not a string?
		# [ error ] ofAppGLFWWindow: 65545: X11: Failed to convert selection to string

		
		# ofSetColor(255,0,0, 255) # rgba
		# ofDrawCircle(*@p,z, 20)
		
		@p_history.reverse_each.each_with_index do |p, i|
			next unless i % 3 == 0
			
			x,y = p
			ofSetColor(255,0,0, 255-i*10) # rgba
			
			r = 20-i/2
			r = 0 if r < 0
			ofDrawCircle(x,y,z, r)
		end
		
		
		ofSetColor(0, 141, 240, 255) # rgba
		x,y = @p
			# not sure why, but need to get variables again?
			# if you don't, the text trails behind the desired position by a couple seconds.
		@font.draw_string("TrueTypeFont Test!", x, y)
		
		
		
		
		ofSetColor(255, 255, 255, 255)
		# x = y = 300
		width = height = 100
		@texture.draw_wh(
			x,y,	z,
			width, height
		)
	end
	
	def on_exit
		super()
	end
	
	
	
	
	def key_pressed(key)
		super(key)
		
		begin
			string = 
				if key == 32
					"<space>"
				elsif key == 13
					"<enter>"
				else
					key.chr
				end
				
			puts string
		rescue RangeError => e
			
		end
	end
	
	def key_released(key)
		super(key)
	end
	
	
	
	
	
	def mouse_moved(x,y)
		@p = [x,y]
	end
	
	def mouse_pressed(x,y, button)
		super(x,y, button)
		
		ofExit() if button == 8
		# different window systems return different numbers
		# for the 'forward' mouse button:
			# GLFW: 4
			# Glut: 8
		# TODO: set button codes as constants?
		
		
		
		if button == 7
			# --- test Point class (wraps ofPoint, which is an alias for ofVec3f)
			point = Oni::Point.new(200, 200, 0)
			puts point
			puts point.x
			
				point.x = 100
				
			puts point.x
			puts point
			
			
			# self.set_window_position(200, 200) 
			
			
			
			# --- toggle cursor visibility
			@cursor_visible = true if @cursor_visible.nil?
			p @cursor_visible
			if @cursor_visible
				hide_cursor
			else
				show_cursor
			end
				
			@cursor_visible = !@cursor_visible
		elsif button == 5
			self.clipboard_string = "hello world"
		end
	end
	
	def mouse_released(x,y, button)
		super(x,y, button)
	end
	
	def mouse_dragged(x,y, button)
		super(x,y, button)
	end
end

x = Window.new
x.show
