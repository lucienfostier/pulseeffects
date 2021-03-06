/*
 *  Copyright © 2017-2020 Wellington Wallace
 *
 *  This file is part of PulseEffects.
 *
 *  PulseEffects is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  PulseEffects is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with PulseEffects.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef FILTER_HPP
#define FILTER_HPP

#include "plugin_base.hpp"

class Filter : public PluginBase {
 public:
  Filter(const std::string& tag, const std::string& schema, const std::string& schema_path);
  Filter(const Filter&) = delete;
  auto operator=(const Filter&) -> Filter& = delete;
  Filter(const Filter&&) = delete;
  auto operator=(const Filter &&) -> Filter& = delete;
  ~Filter();

  GstElement* filter = nullptr;

  sigc::connection input_level_connection, output_level_connection;

  sigc::signal<void, std::array<double, 2>> input_level, output_level;

 private:
  void bind_to_gsettings();
};

#endif
