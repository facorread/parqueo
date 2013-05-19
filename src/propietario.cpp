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

#include "propietario.h"
#include <fstream>

std::istream& operator>> (std::istream& in, propietarioCls& propietario) {
	in >> propietario.mNombre1;
	if(in.eof())
		return in;
	if(propietario.mNombre1.empty()) {
		std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() Hace falta un nombre 1 " << in.peek() << "; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
		exit(1);
	}
	if(in.fail()) {
		std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() Fallo en la lectura de un nombre 1; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
		exit(1);
	}
	in.ignore();
	in >> propietario.mNombre2;
	if(in.fail())
		in.clear();
	in >> propietario.mApartamento1;
	if(in.fail()) {
		if(!propietario.mNombre2.empty())
			std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() Los propietarios " << propietario.mNombre1 << " y " << propietario.mNombre2 << " no tienen apartamento 1; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
		else
			std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() El propietario " << propietario.mNombre1 << " no tiene apartamento 1; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
		exit(1);
	}
	in >> propietario.mApartamento2;
	in.clear();
	in >> propietario.mApartamento3;
	in.clear();
	in >> propietario.mApartamento4;
	in.clear();
	std::string residente;
	in.ignore();
	in >> residente;
	if(in.fail()) {
		if(!propietario.mNombre2.empty())
			std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() Los propietarios " << propietario.mNombre1 << " y " << propietario.mNombre2 << " no tienen registro de ser residentes; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
		else
			std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() El propietario " << propietario.mNombre1 << " no tiene registro de ser residente; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
		exit(1);
	}
	if(residente == "Si")
		propietario.mResidente = true;
	else if(residente == "No")
		propietario.mResidente = false;
	else {
		if(!propietario.mNombre2.empty())
			std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() Los propietarios " << propietario.mNombre1 << " y " << propietario.mNombre2 << " tienen residencia " << propietario.mResidente << "; solamente se aceptan valores Si o No; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
		else
			std::cerr << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << "() El propietario " << propietario.mNombre1 << " tiene residencia " << propietario.mResidente << "; solamente se aceptan valores Si o No; por favor corrija la planilla y vuelva a ejecutar el programa." << std::endl;
		exit(1);
	}
	in.ignore();
	in >> propietario.mTelefono1;
	in.clear();
	in.ignore();
	in >> propietario.mTelefono2;
	in.clear();
	in >> propietario.mVehiculo1;
	in.clear();
	in >> propietario.mVehiculo2;
	in.clear();
	in >> propietario.mVehiculo3;
	in.clear();
	in >> propietario.mVehiculo4;
	in.clear();
	return in;
}

std::ostream& operator<< (std::ostream& out, const propietarioCls& propietario) {
	out << "," << propietario.mNombre1 << "," << propietario.mNombre2 << "," << propietario.mApartamento1 << "," << propietario.mApartamento2 << "," << propietario.mApartamento3 << "," << propietario.mApartamento4 << "," << propietario.mVehiculo1 << "," << propietario.mVehiculo2 << "," << propietario.mVehiculo3 << "," << propietario.mVehiculo4;
	return out;
}
