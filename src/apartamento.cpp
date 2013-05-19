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
	bool datosLeidos(false);
	in.ignore();
	in >> apartamento.mTorre;
	if(in.fail()) {
		in.clear();
	} else
		datosLeidos = true;
	in.ignore();
	in >> apartamento.mApartamento;
	if(in.fail()) {
		if(datosLeidos) {
			std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() Falta el número de un apartamento para la torre " << apartamento.mTorre << "; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
			exit(1);
		}
	} else if(!datosLeidos) {
		std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() Falta el número de torre para el apartamento " << apartamento.mApartamento << "; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
		exit(1);
	}
	if(datosLeidos) {
		div_t pisoApto(std::div(apartamento.mApartamento - 1, 100));
		div_t torreApto(std::div(pisoApto.rem, 4));
		int torreCalculada(torreApto.quot);
		++torreCalculada;
		if(torreCalculada != apartamento.mTorre) {
			std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() El apartamento " << apartamento.mApartamento << " es de la torre " << torreCalculada << " (calculada), que no corresponde a la torre " << apartamento.mTorre << "; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
			exit(1);
		}
		in.clear();
	} else
		in.setstate(std::ios_base::failbit);
	return in;
}

void apartamentoCls::imprimirEncabezado(std::ostream& out, const int numero) {
	std::string numeroString;
	if(numero)
		numeroString = std::string(" ") + std::to_string(numero);
	out << ",Torre" << numeroString << ",Apartamento" << numeroString;
}

std::ostream& operator<< (std::ostream& out, const apartamentoCls& apartamento) {
	if(apartamento.mTorre)
		out << "," << apartamento.mTorre << "," << apartamento.mApartamento;
	else
		out << ",,";
	return out;
}
