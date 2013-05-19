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

#include "vehiculo.h"

std::istream& operator>> (std::istream& in, vehiculoCls& vehiculo) {
	bool datosLeidos(true);
	std::string tipo;
	in.ignore();
	in >> tipo;
	if(tipo == "Automovil")
		vehiculo.mTipo = eTipoVehiculo::automovil;
	else if(tipo == "Motocicleta")
		vehiculo.mTipo = eTipoVehiculo::motocicleta;
	else if(in.fail())
		datosLeidos = false;
	else {
		std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() El tipo de vehículo " << tipo << " es inválido; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
		exit(1);
	}
	in.ignore();
	in >> vehiculo.mPlaca;
	if(datosLeidos) {
		if(in.fail()) {
			std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() Falta la placa de un vehículo; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
			exit(1);
		}
	} else {
		if(!vehiculo.mPlaca.empty()) {
			std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() Falta el tipo del vehículo " << vehiculo.mPlaca << "; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
			exit(1);
		}
		in.clear();
	}
	in.ignore();
	in >> vehiculo.mMarca;
	if(datosLeidos) {
		if(in.fail()) {
			std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() Falta la marca de un vehículo; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
			exit(1);
		}
	} else {
		if(!vehiculo.mPlaca.empty()) {
			std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() Falta el tipo del vehículo " << vehiculo.mPlaca << "; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
			exit(1);
		}
		in.clear();
	}
	in.ignore();
	in >> vehiculo.mModelo;
	if(datosLeidos) {
		if(in.fail()) {
			std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() Falta el modelo de un vehículo; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
			exit(1);
		}
	} else {
		if(!vehiculo.mPlaca.empty()) {
			std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() Falta el tipo del vehículo " << vehiculo.mPlaca << "; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
			exit(1);
		}
		in.clear();
	}
	in.ignore();
	in >> vehiculo.mColor;
	if(datosLeidos) {
		if(in.fail()) {
			std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() Falta el color de un vehículo; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
			exit(1);
		}
	} else {
		if(!vehiculo.mPlaca.empty()) {
			std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() Falta el tipo del vehículo " << vehiculo.mPlaca << "; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
			exit(1);
		}
		in.clear();
	}
	in.ignore();
	in >> vehiculo.mProducido;
	if(datosLeidos) {
		if(in.fail()) {
			std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() Falta el año de un vehículo; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
			exit(1);
		}
	} else {
		if(!vehiculo.mPlaca.empty()) {
			std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() Falta el tipo del vehículo " << vehiculo.mPlaca << "; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
			exit(1);
		}
		in.clear();
	}
	return in;
}

void vehiculoCls::imprimirEncabezado(std::ostream& out, const int numero) {
	std::string numeroString;
	if(numero)
		numeroString = std::string(" ") + std::to_string(numero);
	out << ",Tipo vehículo" << numeroString << ",Placa" << numeroString << ",Marca" << numeroString << ",Modelo" << numeroString << ",Color" << numeroString << ",Año" << numeroString;
}

std::ostream& operator<< (std::ostream& out, const vehiculoCls& vehiculo) {
	switch(vehiculo.mTipo) {
		case eTipoVehiculo::automovil:
			out << "Automovil";
			break;
		case eTipoVehiculo::motocicleta:
			out << "Motocicleta";
			break;
		case eTipoVehiculo::vacio:
			return out;
			break;
	};
	out << "," << vehiculo.mPlaca << "," << vehiculo.mMarca << "," << vehiculo.mModelo << "," << vehiculo.mColor << ",";
	if(vehiculo.mTipo != eTipoVehiculo::vacio)
		out << vehiculo.mProducido;
	return out;
}
