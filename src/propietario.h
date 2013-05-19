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
		/// Primer apartamento.
		apartamentoCls mApartamento1;
		/// Segundo apartamento.
		apartamentoCls mApartamento2;
		/// Tercer apartamento.
		apartamentoCls mApartamento3;
		/// Cuarto apartamento.
		apartamentoCls mApartamento4;
		/// El propietario reside en el conjunto, si o no.
		bool mResidente;
		/// Teléfono de contacto 1.
		std::string mTelefono1;
		/// Teléfono de contacto 2.
		std::string mTelefono2;
		/// Primer vehículo del propietario.
		vehiculoCls mVehiculo1;
		/// Segundo vehículo del propietario.
		vehiculoCls mVehiculo2;
		/// Tercer vehículo del propietario.
		vehiculoCls mVehiculo3;
		/// Cuarto vehículo del propietario.
		vehiculoCls mVehiculo4;
		/// Operador para leer los datos de un propietario desde un archivo.
		friend std::istream& operator>> (std::istream& in, propietarioCls& propietario);
		/// Imprime el encabezado de apartamentos para elaborar la planilla.
		static void imprimirEncabezado(std::ostream& out, const int numero);
		/// Operator para imprimir los datos de un propietario a un archivo.
		friend std::ostream& operator<< (std::ostream& out, const propietarioCls& propietario);
};

/// Operador para leer los datos de un propietario desde un archivo.
std::istream& operator>> (std::istream& in, propietarioCls& propietario);
/// Operator para imprimir los datos de un propietario a un archivo.
std::ostream& operator<< (std::ostream& out, const propietarioCls& propietario);
