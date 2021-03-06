/*
  Copyright 2010 SINTEF ICT, Applied Mathematics.

  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "config.h"

#include <opm/core/utility/StopWatch.hpp>
#include <opm/porsol/blackoil/co2fluid/BlackoilCo2PVT.hpp>

#include <iostream>

int main(int argc, char** argv)
try
{
    double temperature = 300.;
    if (argc == 2) {
        temperature = std::atof(argv[1]);
    }

    Opm::BlackoilCo2PVT boPvt;
    Opm::DeckConstPtr deck; // <- uninitalized pointer!
    Opm::time::StopWatch clock;

    clock.start();
    boPvt.init(deck);

    boPvt.generateBlackOilTables(temperature);
    clock.stop();

    std::cout << "\n\nInitialisation and table generation - clock time (secs): "
              << clock.secsSinceStart() << std::endl;
}
catch (const std::exception &e) {
    std::cerr << "Program threw an exception: " << e.what() << "\n";
    throw;
}
