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

#include <string>
#include <iostream>

/// Define un vehículo.
class vehiculoCls;

/// Define los tipos de vehículo que pueden ser parqueados.
enum class eTipoVehiculo {
	automovil,
	motocicleta
};

class vehiculoCls {
	private:
		/// Tipo de vehículo.
		eTipoVehiculo mTipo;
		/// Placa del vehículo.
		std::string mPlaca;
		/// Marca del vehículo: Renault, Nissan, Chevrolet.
		std::string mMarca;
		/// Modelo del vehículo: Sandero, Sentra, Corsa...
		std::string mModelo;
		/// Color del vehículo.
		std::string mColor;
		/// Año de producción del vehículo.
		int mProducido;
		/// Operador para leer los datos de un vehículo desde un archivo.
		friend std::istream& operator>> (std::istream& in, vehiculoCls& vehiculo);
		/// Imprime el encabezado de vehículos para elaborar la planilla.
		static void imprimirEncabezado(std::ostream& out, const int numero);
		/// Operator para imprimir los datos de un vehículo a un archivo.
		friend std::ostream& operator<< (std::ostream& out, const vehiculoCls& vehiculo);
};

/// Operador para leer los datos de un vehículo desde un archivo.
std::istream& operator>> (std::istream& in, vehiculoCls& vehiculo);
/// Operator para imprimir los datos de un vehículo a un archivo.
std::ostream& operator<< (std::ostream& out, const vehiculoCls& vehiculo);
