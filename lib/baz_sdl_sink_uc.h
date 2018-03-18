/* -*- c++ -*- */
/*
 * Copyright 2006,2012 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_BAZ_SDL_SINK_UC_H
#define INCLUDED_BAZ_SDL_SINK_UC_H

#include <gnuradio/video_sdl/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace baz {

    /*!
     * \brief video sink using SDL
     *
     * input signature is one, two or three streams of uchar.
     * One stream: stream is grey (Y)
     * two streems: first is grey (Y), second is alternating U and V
     * Three streams: first is grey (Y), second is U, third is V
     * Input samples must be in the range [0,255].
     */
    class BAZ_API sdl_sink_uc : virtual public sync_block
    {
    public:
      // gr::baz::sdl_sink_uc::sptr
      typedef boost::shared_ptr<sdl_sink_uc> sptr;

      static sptr make(double framerate,
		       int width, int height,
		       unsigned int format,
		       int dst_width, int dst_height, const std::string filename = "", bool manual_flip = false, const std::string font_path = "");

      virtual void flip(void)=0;
    };

  } /* namespace baz */
} /* namespace gr */

#endif /* INCLUDED_BAZ_SDL_SINK_UC_H */