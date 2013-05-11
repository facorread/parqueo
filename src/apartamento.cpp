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

#include "apartamento.h"

std::istream& operator>> (std::istream& in, apartamentoCls& apartamento) {
	in >> apartamento.mTorre >> apartamento.mApartamento;
	if(static_cast<int>(apartamento.mApartamento / 4.0f) != apartamento.mTorre) {
		std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() El apartamento " << apartamento.mApartamento << " no corresponde a la torre " << apartamento.mTorre << "; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
		exit(1);
	}
	return in;
}

void apartamentoCls::imprimirEncabezado(std::ostream& out, const int numero) {
	std::string numeroString;
	if(numero)
		numeroString = std::string(" ") + std::to_string(numero);
	out << ",Torre" << numeroString << ",Apartamento" << numeroString;
}

std::ostream& operator<< (std::ostream& out, const apartamentoCls& apartamento) {
	out << "," << apartamento.mTorre << "," << apartamento.mApartamento;
	return out;
}
