/* This file is part of Parqueo.

Parqueo is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Parqueo is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Parqueo.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <list>
#include "vehiculo.h"
#include "apartamento.h"

class propietarioCls {
	private:
		/// Nombre del primer propietario.
		std::string mNombre1;
		/// Nombre del segundo propietario.
		std::string mNombre2;
		/// Representa la lista de apartamentos del propietario.
		typedef std::list<apartamentoCls> listaApartamentosCls;
		/// Lista de apartamentos del propietario.
		listaApartamentosCls mApartamento;
		/// Representa la lista de vehículos.
		typedef std::list<vehiculoCls> listaVehiculosCls;
		/// Lista de vehículos del propietario.
		listaVehiculosCls mVehiculo;
};
