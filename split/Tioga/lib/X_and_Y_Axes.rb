#  X_and_Y_Axes.rb

module Tioga

# These are the methods and attributes for the plot axes.

class X_and_Y_Axes < Doc < FigureMaker

# :call-seq:
#   show_xaxis
#
# If the flag xaxis_visible is currently +true+, then this routine shows the x axis 
# at the location specified by xaxis_loc.  If the flag is +false+, it simply returns.
    def show_xaxis
    end

# :call-seq:
#   show_yaxis
#
# If the flag yaxis_visible is currently +true+, then this routine shows the y axis 
# at the location specified by yaxis_loc.  If the flag is +false+, it simply returns.
    def show_yaxis
    end

# :call-seq:
#   show_top_edge
#
# If the flag top_edge_visible is +true+ and the xaxis_loc is not +TOP+, then
# shows the top edge of the frame.  Otherwise, simply returns.
    def show_top_edge
    end

# :call-seq:
#   show_bottom_edge
#
# If the flag bottom_edge_visible is +true+ and the xaxis_loc is not +BOTTOM+, then
# shows the bottom edge of the frame.  Otherwise, simply returns.
    def show_bottom_edge
    end

# :call-seq:
#   show_left_edge
#
# If the flag left_edge_visible is +true+ and the yaxis_loc is not +LEFT+, then
# shows the left edge of the frame.  Otherwise, simply returns.
    def show_left_edge
    end

# :call-seq:
#   show_right_edge
#
# If the flag right_edge_visible is +true+ and the yaxis_loc is not +RIGHT+, then
# shows the right edge of the frame.  Otherwise, simply returns.
    def show_right_edge
    end

# :call-seq:
#               xaxis_reversed                                     
#
# Flag is +true+ if the bounds_left is not the bounds_xmin.
   def xaxis_reversed
   end

# :call-seq:
#               yaxis_reversed                                     
#
# Flag is +true+ if the bounds_bottom is not the bounds_ymin.
   def yaxis_reversed
   end
   

# :call-seq:
#               top_edge_type                                     
#               top_edge_type = an_edge_type
#
# Determines the axis type to use when showing the top edge of a plot.  Valid
# types are the following predefined constants: +AXIS_HIDDEN+, +AXIS_LINE_ONLY+,
# +AXIS_WITH_MAJOR_TICKS_ONLY+, +AXIS_WITH_TICKS_ONLY+, +AXIS_WITH_MAJOR_TICKS_AND_NUMERIC_LABELS+,
# and +AXIS_WITH_TICKS_AND_NUMERIC_LABELS+.
   def top_edge_type
   end
   

# :call-seq:
#               top_edge_visible                                     
#               top_edge_visible = false
#
# If +true+, then it is okay for Tioga to show the top edge of a plot.  If +false+,
# then calls on show_top_edge return immediately.
# This attribute is "one-way-only" in that it starts +true+ and can be
# set +false+, but cannot be reset to +true+ except by restoring the
# graphics state in which is was still +true+.  This is intended
# to help control the behavior of plots when embedded as subplots in a
# larger configuration.  Note that this does not effect showing the x axis
# on the top; it only applies to calls on show_top_edge.
   def top_edge_visible
   end

# :call-seq:
#               bottom_edge_type                                     
#               bottom_edge_type = an_edge_type
#
# Determines the axis type to use when showing the bottom edge of a plot.  Valid
# types are the following predefined constants: +AXIS_HIDDEN+, +AXIS_LINE_ONLY+,
# +AXIS_WITH_MAJOR_TICKS_ONLY+, +AXIS_WITH_TICKS_ONLY+, +AXIS_WITH_MAJOR_TICKS_AND_NUMERIC_LABELS+,
# and +AXIS_WITH_TICKS_AND_NUMERIC_LABELS+.
   def bottom_edge_type
   end
   

# :call-seq:
#               bottom_edge_visible                                     
#               bottom_edge_visible = false
#
# If +true+, then it is okay for Tioga to show the bottom edge of a plot.  If +false+,
# then calls on show_bottom_edge return immediately.
# This attribute is "one-way-only" in that it starts +true+ and can be
# set +false+, but cannot be reset to +true+ except by restoring the
# graphics state in which is was still +true+.  This is intended
# to help control the behavior of plots when embedded as subplots in a
# larger configuration.  Note that this does not effect showing the x axis
# on the bottom; it only applies to calls on show_bottom_edge.
   def bottom_edge_visible
   end
    

# :call-seq:
#               left_edge_type                                     
#               left_edge_type = an_edge_type
#
# Determines the axis type to use when showing the left edge of a plot.  Valid
# types are the following predefined constants: +AXIS_HIDDEN+, +AXIS_LINE_ONLY+,
# +AXIS_WITH_MAJOR_TICKS_ONLY+, +AXIS_WITH_TICKS_ONLY+, +AXIS_WITH_MAJOR_TICKS_AND_NUMERIC_LABELS+,
# and +AXIS_WITH_TICKS_AND_NUMERIC_LABELS+.
   def left_edge_type
   end
   

# :call-seq:
#               left_edge_visible                                     
#               left_edge_visible = false
#
# If +true+, then it is okay for Tioga to show the left edge of a plot.  If +false+,
# then calls on show_left_edge return immediately.
# This attribute is "one-way-only" in that it starts +true+ and can be
# set +false+, but cannot be reset to +true+ except by restoring the
# graphics state in which is was still +true+.  This is intended
# to help control the behavior of plots when embedded as subplots in a
# larger configuration.  Note that this does not effect showing the y axis
# on the left; it only applies to calls on show_left_edge.
   def left_edge_visible
   end

# :call-seq:
#               right_edge_type                                     
#               right_edge_type = an_edge_type
#
# Determines the axis type to use when showing the right edge of a plot.  Valid
# types are the following predefined constants: +AXIS_HIDDEN+, +AXIS_LINE_ONLY+,
# +AXIS_WITH_MAJOR_TICKS_ONLY+, +AXIS_WITH_TICKS_ONLY+, +AXIS_WITH_MAJOR_TICKS_AND_NUMERIC_LABELS+,
# and +AXIS_WITH_TICKS_AND_NUMERIC_LABELS+.
   def right_edge_type
   end
   
# :call-seq:
#               right_edge_visible                                     
#               right_edge_visible = false
#
# If +true+, then it is okay for Tioga to show the right edge of a plot.  If +false+,
# then calls on show_right_edge return immediately.
# This attribute is "one-way-only" in that it starts +true+ and can be
# set +false+, but cannot be reset to +true+ except by restoring the
# graphics state in which is was still +true+.  This is intended
# to help control the behavior of plots when embedded as subplots in a
# larger configuration.  Note that this does not effect showing the y axis
# on the right; it only applies to calls on show_right_edge.
   def right_edge_visible
   end


# Show one of the plot axes.  If _loc_ is +LEFT+, +RIGHT+, or +AT_X_ORIGIN+, and 
# yaxis_visible is +true+, then the axis is shown using the current y axis settings.
# If _loc_ is  +TOP+, +BOTTOM+,  or +AT_Y_ORIGIN+, and xaxis_visible is +true+, then
# the axis is shown using the current x axis settings.
   def show_axis(loc)
   end

# Show one of the plot edges.  The _loc_ argument must be one of +LEFT+, +RIGHT+, +TOP+, or +BOTTOM+.
# Left and right edges are shown using the current y axis settings.  Top and bottom edges are shown
# using the x axis settings.  If the corresponding edge_visible attribute has been set false, this command
# simply returns without doing anything.
   def show_edge(loc)
   end

# :call-seq:
#               xaxis_visible
#               xaxis_visible = false
#
# If +true+, then it is okay for Tioga to show the x axis of a plot.  If +false+,
# then calls on show_axis for the x axis return immediately.
# This attribute is "one-way-only" in that it starts +true+ and can be
# set +false+, but cannot be reset to +true+ except by restoring the
# graphics state in which is was still +true+.  This is intended
# to help control the behavior of plots when embedded as subplots in a
# larger configuration.  Note that this does not effect showing the top or bottom edges;
# it only applies to calls on show_axis.
   def xaxis_visible
   end

# :call-seq:
#               xaxis_loc
#               xaxis_loc = a_location
#
# Determines the location of the x axis.  Valid locations are given as the
# following predefined constants: +BOTTOM+, +TOP+, and +AT_Y_ORIGIN+. 
   def xaxis_loc
   end

# :call-seq:
#               xaxis_type
#               xaxis_type = an_axis_type_value
#
# Determines the axis type to use when showing the x axis of a plot.  Valid
# types are the following predefined constants: +AXIS_HIDDEN+, +AXIS_LINE_ONLY+,
# +AXIS_WITH_MAJOR_TICKS_ONLY+, +AXIS_WITH_TICKS_ONLY+, +AXIS_WITH_MAJOR_TICKS_AND_NUMERIC_LABELS+,
# and +AXIS_WITH_TICKS_AND_NUMERIC_LABELS+.
   def xaxis_type
   end

# :call-seq:
#               xaxis_numeric_label_decimal_digits
#               xaxis_numeric_label_decimal_digits = an_integer_value
#
# If non-negative, then use this number of digits after the decimal when creating numeric
# labels for the x axis.
   def xaxis_numeric_label_decimal_digits
   end

# :call-seq:
#               xaxis_digits_max
#               xaxis_digits_max = an_integer_value
#
# If non-zero and Tioga is creating numeric labels for the x axis, then numeric label 
# will be switched to exponential format if it requires more than this number of digits.
   def xaxis_digits_max
   end

# :call-seq:
#               xaxis_use_fixed_pt
#               xaxis_use_fixed_pt = true_or_false
#
# If this flag is +true+, and Tioga is creating numeric labels for the x axis,
# and the xaxis_log_values flag is also +true+,
# then the labels will be shown using fixed point notation rather than exponential.
# For example, a label at x location 3.0 will display as "1000" rather than as "10^3",
# and a label at x == -2.0 will display as "0.01" rather than as "10^-2".
   def xaxis_use_fixed_pt
   end

# :call-seq:
#               xaxis_number_of_minor_intervals
#               xaxis_number_of_minor_intervals = an_integer_value
#
# Determines the number of minor intervals making up the distance between major ticks marks
# on the x axis.  If this is set to 0, then Tioga will pick the number.
   def xaxis_number_of_minor_intervals
   end

# :call-seq:
#               xaxis_min_between_major_ticks
#               xaxis_min_between_major_ticks = a_float
#
# When Tioga picks the interval between major tick marks on the x axis, it will ensure that
# the interval is at least this large.  Note that this distance is given in units of the
# default text height rather than in x coordinates.
   def xaxis_min_between_major_ticks
   end

# :call-seq:
#               xaxis_tick_labels
#               xaxis_tick_labels = array_or_nil
#
# If +nil+, then Tioga will create numeric labels for the major ticks on the x axis.
# Otherwise, you must also specify xaxis_locations_for_major_ticks, and xaxis_tick_labels
# must be an equal length array of strings giving the corresponding labels.
#
# See also yaxis_tick_labels.
   def xaxis_tick_labels
   end
   
# :call-seq:
#               xaxis_locations_for_major_ticks
#               xaxis_locations_for_major_ticks = a_dvector_or_nil
#
# If +nil+, then Tioga will pick locations for major ticks on the x axis.  Otherwise, this should be
# Dvector of locations in x figure coordinates in strictly increasing order. 
   def xaxis_locations_for_major_ticks
   end

# :call-seq:
#               xaxis_locations_for_minor_ticks
#               xaxis_locations_for_minor_ticks = a_dvector_or_nil
#
# If +nil+, then Tioga will pick locations for minor ticks on the x axis.  Otherwise, this should be
# Dvector of locations in x figure coordinates in strictly increasing order. 
   def xaxis_locations_for_minor_ticks
   end
   
# :call-seq:
#               xaxis_numeric_label_decimal_digits
#               xaxis_numeric_label_decimal_digits = an_integer_value
#
# If 0, then Tioga will pick the interval between major tick marks on the y axis.
# Otherwise, this will be used as the interval in y coordinates for the spacing between major ticks.
   def yaxis_tick_interval
   end

# :call-seq:
#               xaxis_log_values
#               xaxis_log_values = true_or_false
#
# If +true+, then locations along the x axis are to be treated as log values (base 10).
# This changes both the default placing of tick marks and the appearance of numeric labels.
   def xaxis_log_values
   end

# :call-seq:
#               xaxis_ticks_inside
#               xaxis_ticks_inside = true_or_false
#
# If +true+, then ticks will be added along the x axis inside the plot frame.
# If +false+, then no ticks will appear inside the frame along the x axis.
   def xaxis_ticks_inside
   end 

# :call-seq:
#               xaxis_ticks_outside
#               xaxis_ticks_outside = true_or_false
#
# If +true+, then ticks will be added along the x axis outside the plot frame.
# If +false+, then no ticks will appear outside the frame along the x axis.
   def xaxis_ticks_outside
   end

# :call-seq:
#               xaxis_major_tick_length
#               xaxis_major_tick_length = a_float
#
# Length of major ticks on the x axis measured in units of the default text height.
   def xaxis_major_tick_length
   end

# :call-seq:
#               xaxis_minor_tick_length
#               xaxis_minor_tick_length = a_float
#
# Length of minor ticks on the x axis measured in units of the default text height.
   def xaxis_minor_tick_length
   end

# :call-seq:
#               xaxis_line_width
#               xaxis_line_width = a_float
#
# Value for the line_width attribute when painting the x axis line.
   def xaxis_line_width
   end 

# :call-seq:
#               xaxis_major_tick_width
#               xaxis_major_tick_width = a_float
#
# Value for the line_width attribute when painting the x axis major tick marks.
   def xaxis_major_tick_width
   end

# :call-seq:
#               xaxis_minor_tick_width
#               xaxis_minor_tick_width = a_float
#
# Value for the line_width attribute when painting the x axis minor tick marks.
   def xaxis_minor_tick_width
   end

# :call-seq:
#               xaxis_stroke_color
#               xaxis_stroke_color = color_value
#
# Value for the stroke_color attribute when painting the x axis.
   def xaxis_stroke_color
   end

# :call-seq:
#               xaxis_numeric_label_scale
#               xaxis_numeric_label_scale = a_float
#
# Scaling factor relative to default_text_scale for the numeric labels on the x axis in plots.
   def xaxis_numeric_label_scale
   end

# :call-seq:
#               xaxis_numeric_label_shift
#               xaxis_numeric_label_shift = a_float
#
# Distance to shift the reference point for showing numeric labels on the x axis
# measured in character heights with positive directed out away from the plot for
# x axis on top or bottom, or toward positive y values for x axis at y origin.
   def xaxis_numeric_label_shift
   end

# :call-seq:
#               xaxis_numeric_label_angle
#               xaxis_numeric_label_angle = a_float_in_degrees
#
# Numeric labels on the x axis are rotated by this angle from vertical.
   def xaxis_numeric_label_angle
   end

# :call-seq:
#               xaxis_numeric_label_alignment
#               xaxis_numeric_label_alignment = an_alignment
#
# The #alignment setting for numeric labels on the x axis.
   def xaxis_numeric_label_alignment
   end

# :call-seq:
#               xaxis_numeric_label_justification
#               xaxis_numeric_label_justification = a_justification
#
# The #justification setting for numeric labels on the x axis.
   def xaxis_numeric_label_justification
   end

# :call-seq:
#               yaxis_visible
#               yaxis_visible = false
#
# If +true+, then it is okay for Tioga to show the y axis of a plot.  If +false+,
# then calls on show_axis for the y axis return immediately.
# This attribute is "one-way-only" in that it starts +true+ and can be
# set +false+, but cannot be reset to +true+ except by restoring the
# graphics state in which is was still +true+.  This is intended
# to help control the behavior of plots when embedded as subplots in a
# larger configuration.  Note that this does not effect showing the left or right edges;
# it only applies to calls on show_axis.
   def yaxis_visible
   end

# :call-seq:
#               yaxis_loc
#               yaxis_loc = a_location
#
# Determines the location of the y axis.  Valid locations are given as the
# following predefined constants: +LEFT+, +RIGHT+, and +AT_X_ORIGIN+. 
   def yaxis_loc
   end

# :call-seq:
#               yaxis_type
#               yaxis_type = an_axis_type_value
#
# Determines the axis type to use when showing the y axis of a plot.  Valid
# types are the following predefined constants: +AXIS_HIDDEN+, +AXIS_LINE_ONLY+,
# +AXIS_WITH_MAJOR_TICKS_ONLY+, +AXIS_WITH_TICKS_ONLY+, +AXIS_WITH_MAJOR_TICKS_AND_NUMERIC_LABELS+,
# and +AXIS_WITH_TICKS_AND_NUMERIC_LABELS+.
   def yaxis_type
   end
   
# :call-seq:
#               yaxis_numeric_label_decimal_digits
#               yaxis_numeric_label_decimal_digits = an_integer_value
#
# If non-negative, then use this number of digits after the decimal when creating numeric
# labels for the y axis.
   def yaxis_numeric_label_decimal_digits
   end

# :call-seq:
#               yaxis_digits_max
#               yaxis_digits_max = an_integer_value
#
# If non-zero and Tioga is creating numeric labels for the y axis, then numeric label 
# will be switched to exponential format if it requires more than this number of digits.
   def yaxis_digits_max
   end

# :call-seq:
#               yaxis_use_fixed_pt
#               yaxis_use_fixed_pt = true_or_false
#
# If this flag is +true+, and Tioga is creating numeric labels for the y axis,
# and the yaxis_log_values flag is also +true+,
# then the labels will be shown using fixed point notation rather than exponential.
# For example, a label at y location 3.0 will display as "1000" rather than as "10^3",
# and a label at y == -2.0 will display as "0.01" rather than as "10^-2".
   def yaxis_use_fixed_pt
   end

# :call-seq:
#               yaxis_number_of_minor_intervals
#               yaxis_number_of_minor_intervals = an_integer_value
#
# Determines the number of minor intervals making up the distance between major ticks marks
# on the y axis.  If this is set to 0, then Tioga will pick the number.
   def yaxis_number_of_minor_intervals
   end
# :call-seq:
#               yaxis_min_between_major_ticks
#               yaxis_min_between_major_ticks = a_float
#
# When Tioga picks the interval between major tick marks on the y axis, it will ensure that
# the interval is at least this large.  Note that this distance is given in units of the
# default text height rather than in y coordinates.
   def yaxis_min_between_major_ticks
   end

=begin rdoc
:call-seq:
               yaxis_tick_labels
               yaxis_tick_labels = array_or_nil

If +nil+, then Tioga will create numeric labels for the major ticks on the y axis.
Otherwise, you must also specify yaxis_locations_for_major_ticks, and yaxis_tick_labels
must be an equal length array of strings giving the corresponding labels.

See also xaxis_tick_labels.

Examples

    def special_y
        t.ylabel_shift += 2
        t.do_box_labels('Special Y Axis', 'Position', 'Y Values')
        t.yaxis_numeric_label_angle = -90
        t.yaxis_locations_for_major_ticks = [ 
            -10.0, -6.0, -PI, 0.0, PI, 6.0, 10.0 ]
        t.yaxis_tick_labels = [ 
            "-IX", "-VI", "$-\\pi$", "$\\mathcal{ZERO}$", "$\\pi$", "VI", "IX" ]
        t.yaxis_type = AXIS_WITH_MAJOR_TICKS_AND_NUMERIC_LABELS
        t.stroke_color = Blue
        t.yaxis_numeric_label_justification = RIGHT_JUSTIFIED
        t.right_edge_type = AXIS_WITH_MAJOR_TICKS_ONLY
        t.yaxis_numeric_label_shift = 0
        xs = @positions; ys = @big_blues
        t.show_plot('boundaries' => plot_boundaries(xs,ys,@margin,-11, 11)) do
            t.append_points_to_path(xs,ys)
            t.stroke
        end
    end

http://theory.kitp.ucsb.edu/~paxton/tioga_jpegs/Special_Y.jpg

=end
   def yaxis_tick_labels
   end

# :call-seq:
#               yaxis_locations_for_major_ticks
#               yaxis_locations_for_major_ticks = a_dvector_or_nil
#
# If +nil+, then Tioga will pick locations for major ticks on the y axis.  Otherwise, this should be
# Dvector of locations in y figure coordinates in strictly increasing order. 
#
# See also yaxis_tick_labels.
#
   def yaxis_locations_for_major_ticks
   end

# :call-seq:
#               yaxis_locations_for_minor_ticks
#               yaxis_locations_for_minor_ticks = a_dvector_or_nil
#
# If +nil+, then Tioga will pick locations for minor ticks on the y axis.  Otherwise, this should be
# Dvector of locations in x figure coordinates in strictly increasing order. 
   def yaxis_locations_for_minor_ticks
   end

# :call-seq:
#               yaxis_log_values
#               yaxis_log_values = true_or_false
#
# If +true+, then locations along the y axis are to be treated as log values (base 10).
# This changes both the default placing of tick marks and the appearance of numeric labels.
   def yaxis_log_values
   end

# :call-seq:
#               yaxis_ticks_inside
#               yaxis_ticks_inside = true_or_false
#
# If +true+, then ticks will be added along the y axis inside the plot frame.
# If +false+, then no ticks will appear inside the frame along the y axis.
   def yaxis_ticks_inside
   end

# :call-seq:
#               yaxis_ticks_outside
#               yaxis_ticks_outside = true_or_false
#
# If +true+, then ticks will be added along the y axis outside the plot frame.
# If +false+, then no ticks will appear outside the frame along the y axis.
   def yaxis_ticks_outside
   end
   
# :call-seq:
#               yaxis_major_tick_length
#               yaxis_major_tick_length = a_float
#
# Length of major ticks on the y axis measured in units of the default text height.
   def yaxis_major_tick_length
   end

# :call-seq:
#               yaxis_minor_tick_length
#               yaxis_minor_tick_length = a_float
#
# Length of minor ticks on the y axis measured in units of the default text height.
   def yaxis_minor_tick_length
   end

# :call-seq:
#               yaxis_line_width
#               yaxis_line_width = a_float
#
# Value for the line_width attribute when painting the y axis line.
   def yaxis_line_width
   end

# :call-seq:
#               yaxis_major_tick_width
#               yaxis_major_tick_width = a_float
#
# Value for the line_width attribute when painting the y axis major tick marks.
   def yaxis_major_tick_width
   end

# :call-seq:
#               yaxis_minor_tick_width
#               yaxis_minor_tick_width = a_float
#
# Value for the line_width attribute when painting the y axis minor tick marks.
   def yaxis_minor_tick_width
   end

# :call-seq:
#               yaxis_stroke_color
#               yaxis_stroke_color = color_value
#
# Value for the stroke_color attribute when painting the y axis.
   def yaxis_stroke_color
   end

# :call-seq:
#               yaxis_numeric_label_scale
#               yaxis_numeric_label_scale = a_float
#
# Scaling factor relative to default_text_scale for the numeric labels on the y axis in plots.
   def yaxis_numeric_label_scale
   end

# :call-seq:
#               yaxis_numeric_label_shift
#               yaxis_numeric_label_shift = a_float
#
# Distance to shift the reference point for showing numeric labels on the y axis
# measured in character heights with positive directed out away from the plot for
# y axis on left or right, or toward positive x values for y axis at x origin.
   def yaxis_numeric_label_shift
   end

# :call-seq:
#               yaxis_numeric_label_angle
#               yaxis_numeric_label_angle = a_float_in_degrees
#
# Numeric labels on the y axis are rotated by this angle from horizontal.
   def yaxis_numeric_label_angle
   end

# :call-seq:
#               yaxis_numeric_label_alignment
#               yaxis_numeric_label_alignment = an_alignment
#
# The #alignment setting for numeric labels on the y axis.
   def yaxis_numeric_label_alignment
   end

# :call-seq:
#               yaxis_numeric_label_justification
#               yaxis_numeric_label_justification = a_justification
#
# The #justification setting for numeric labels on the y axis.
   def yaxis_numeric_label_justification
   end

# :call-seq:
#               yaxis_tick_interval
#               yaxis_tick_interval = a_float
#
# If 0, then Tioga will pick the interval between major tick marks on the x axis.
# Otherwise, this will be used as the interval in x coordinates for the spacing between major ticks.
   def xaxis_tick_interval
   end





end # class
end # module Tioga
