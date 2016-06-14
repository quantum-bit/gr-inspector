/* -*- c++ -*- */
/*
 * Copyright 2016 <+YOU OR YOUR COMPANY+>.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef GR_INSPECTOR_INSPECTOR_SINK_H
#define GR_INSPECTOR_INSPECTOR_SINK_H

#include <complex>

#include <QApplication>
#include <QTimer>
#include <QWidget>
#include <QtGui/QtGui>

#include <qwt_plot.h>
#include <qwt_symbol.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_scale_widget.h>

namespace gr {
	namespace inspector {

		class inspector_plot : public QWidget
		{
		Q_OBJECT

		public:
      inspector_plot(int fft_len, std::vector<double> *buffer, std::vector<float> axis_x, bool* ready, QWidget* parent = NULL);
			~inspector_plot();

		private:
			int d_interval, d_vlen;
			bool* d_ready;
			std::vector<float> d_axis_x, d_axis_y;
			std::vector<double> *d_buffer;
			bool d_autoscale_z;
      double d_samp_rate, d_update_time;
      double* d_freq;
      QwtSymbol *d_symbol;
			QGridLayout *d_layout;

			QwtPlot *d_plot;
			QwtScaleWidget *d_scale;
			QwtPlotCurve *d_curve;
			QwtPlotGrid* d_grid;
			QTimer *d_timer;

			QVector<double> d_plot_data;

		protected:
			void resizeEvent(QResizeEvent * event);

		public slots:
			void refresh();

			void set_axis_x(float start, float step);

		};
	}
}

#endif //GR_INSPECTOR_INSPECTOR_SINK_H