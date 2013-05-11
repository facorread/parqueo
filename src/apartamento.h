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

#include<iostream>

/// Define un apartamento.
class apartamentoCls;

class apartamentoCls {
	private:
		/// Torre.
		int mTorre;
		/// Número de apartamento.
		int mApartamento;
		/// Operador para leer los datos de un apartamento desde un archivo.
		friend std::istream& operator>> (std::istream& in, apartamentoCls& apartamento);
		/// Imprime el encabezado de apartamentos para elaborar la planilla.
		static void imprimirEncabezado(std::ostream& out, const int numero);
		/// Operator para imprimir los datos de un apartamento a un archivo.
		friend std::ostream& operator<< (std::ostream& out, const apartamentoCls& apartamento);
};

/// Operador para leer los datos de un apartamento desde un archivo.
std::istream& operator>> (std::istream& in, apartamentoCls& apartamento);
/// Operator para imprimir los datos de un apartamento a un archivo.
std::ostream& operator<< (std::ostream& out, const apartamentoCls& apartamento);
