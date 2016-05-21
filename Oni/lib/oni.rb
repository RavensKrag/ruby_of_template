puts "load C code..."

# Stolen from Gosu's code to load the dynamic library
if defined? RUBY_PLATFORM and
%w(-win32 win32- mswin mingw32).any? { |s| RUBY_PLATFORM.include? s } then
	ENV['PATH'] = "#{File.dirname(__FILE__)};#{ENV['PATH']}"
end

require 'oni/oni'
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
		# :kb_capital is CAPS LOCK
		# :kb_scroll is scroll lock
		KEY_ID = [:kb_unassigned, :kb_escape,
			
			:kb_1, :kb_2, :kb_3, :kb_4, :kb_5, :kb_6, :kb_7, :kb_8, :kb_9, :kb_0, 
			:kb_minus, :kb_equals, :kb_back, :kb_tab, 
			:kb_q, :kb_w, :kb_e, :kb_r, :kb_t, :kb_y, :kb_u, :kb_i, :kb_o, :kb_p, :kb_lbracket, :kb_rbracket, :kb_return, 
			:kb_lcontrol, :kb_a, :kb_s, :kb_d, :kb_f, :kb_g, :kb_h, :kb_j, :kb_k, :kb_l, :kb_semicolon, :kb_apostrophe, :kb_grave, :kb_lshift, :kb_backslash,
			:kb_z, :kb_x, :kb_c, :kb_v, :kb_b, :kb_n, :kb_m, :kb_comma, :kb_period, :kb_slash, :kb_rshift,
			
			:kb_multiply, :kb_lalt, :kb_space, :kb_capital,
			
			:kb_f1, :kb_f2, :kb_f3, :kb_f4, :kb_f5, :kb_f6, :kb_f7, :kb_f8, :kb_f9, :kb_f10, :kb_numlock, :kb_scroll, 
			
			:kb_numpad7, :kb_numpad8, :kb_numpad9, :kb_subtract, :kb_numpad4, :kb_numpad5, :kb_numpad6, :kb_add, :kb_numpad1, :kb_numpad2, :kb_numpad3, :kb_numpad0, :kb_decimal, 
			
			:kb_oem_102,
			
			nil, nil, :kb_f11, :kb_f12, :kb_f15,
			
			:kb_kana, :kb_abnt_c1, :kb_convert, :kb_noconvert, :kb_yen, :kb_abnt_c2, :kb_numpadequals, :kb_prevtrack, :kb_at, :kb_colon, :kb_underline, :kb_kanji, :kb_stop, :kb_ax, :kb_unlabeled, :kb_nexttrack, :kb_numpadenter, :kb_rcontrol, :kb_mute, :kb_calculator, :kb_playpause, :kb_mediastop, :kb_volumedown, :kb_volumeup, :kb_webhome, :kb_numpadcomma, :kb_divide, :kb_sysrq, :kb_rmenu, :kb_pause, :kb_home, :kb_up, :kb_pgup, :kb_left, :kb_right, :kb_end, :kb_down, :kb_pgdown, :kb_insert, :kb_delete, :kb_lwin, :kb_rwin, :kb_apps, :kb_power, :kb_sleep, :kb_wake, :kb_websearch, :kb_webfavorites, :kb_webrefresh, :kb_webstop, :kb_webforward, :kb_webback, :kb_mycomputer, :kb_mail, :kb_mediaselect,
			# There are 145 symbols listed above
			# That's IDs 0-144 inclusive on both ends
			
			# 145
			nil, 
			# 146
			nil, 
			# 147
			nil, 
			# 148
			nil, 
			# 149
			nil, 
			# 150
			nil, 
			# 151
			nil, 
			# 152
			nil, 
			# 153
			nil, 
			# 154
			nil, 
			# 155
			nil, 
			# 156
			nil, 
			# 157
			:rcontrol, #rcontrol
			# 158
			nil, 
			# 159
			nil, 
			# 160
			nil, 
			# 161
			nil, 
			# 162
			nil, 
			# 163
			nil, 
			# 164
			nil, 
			# 165
			nil, 
			# 166
			nil, 
			# 167
			nil, 
			# 168
			nil, 
			# 169
			nil, 
			# 170
			nil, 
			# 171
			nil, 
			# 172
			nil, 
			# 173
			nil, 
			# 174
			nil, 
			# 175
			nil, 
			# 176
			nil, 
			# 177
			nil, 
			# 178
			nil, 
			# 179
			nil, 
			# 180
			nil, 
			# 181
			nil, 
			# 182
			nil, 
			# 183
			:kb_printscreen, 
			# 184
			:ralt, # ralt
			# 185
			nil, 
			# 186
			nil, 
			# 187
			nil, 
			# 188
			nil, 
			# 189
			nil, 
			# 190
			nil, 
			# 191
			nil, 
			# 192
			nil, 
			# 193
			nil, 
			# 194
			nil, 
			# 195
			nil, 
			# 196
			nil, 
			# 197
			nil, 
			# 198
			nil, 
			# 199-208
			:kb_home, :kb_up, :kb_pgup, nil, :kb_left, :kb_end, :kb_right, :kb_pgdown, :kb_end, :kb_down,
			# 209
			:kb_pgdown, 
			# 210
			:kb_insert,
			# 211
			:kb_delete,
			# 212
			nil, 
			# 213
			nil, 
			# 214
			nil, 
			# 215
			nil, 
			# 216
			nil, 
			# 217
			nil, 
			# 218
			nil, 
			# 219
			:kb_lwin, 
			# 220
			:kb_rwin, 
			# 221
			:kb_menu
		]
		
		def update(dt)
		end
		
		def draw
		end
		
		def button_down(id)
			
		end
		
		def button_up(id)
			
		end
		
		def button_id_to_sym(id)
			return KEY_ID[id]
		end
	end
	
	class Animation
		class Track
			def playing?
				return !ended?
			end
		end
	end
end
