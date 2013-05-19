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

/** \mainpage
\author Fabio Correa (Fabio Andr�s Correa Dur�n)
\date 2013
\copyright This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
\warning This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

\section introduccion Introducci�n
Parqueo ofrece los siguientes servicios:
- Hacer un sorteo de parqueaderos entre una lista de propietarios.
- Organizar autom�viles en parqueaderos cercanos a la torre donde viven los propietarios.
- Organizar motocicletas en los parqueaderos que se han escogido para ellas.

\section funcionamiento Funcionamiento
- El programa lee la informaci�n de veh�culos registrados por los propietarios aspirantes, y los apartamentos de los cuales son due�os.
- Para cada unidad privada aspirante, el programa asigna un cupo.
- El programa hace el sorteo de los cupos favorecidos con parqueo
- El programa agrupa los cupos de autom�vil por torre, y asigna a cada torre el n�mero de parqueaderos cercanos que sea necesario para satisfacer los cupos.
- El programa asigna aleatoriamente los cupos a cada parqueadero por torre.
- El programa asigna aleatoriamente los cupos de motocicleta a los parqueaderos respectivos.
- El programa hace un gr�fico de los parqueaderos y su asignaci�n
- El programa produce la planilla de parqueaderos asignados.

\section Elementos Elementos necesarios para el funcionamiento del programa
- Lista de parqueaderos y torres
*/

#include <iostream>
#include <fstream>
#include "main.h"
#include "locale.h"

/// Locale.
std::locale commaLocale(std::locale::classic(), new commaCls);
/// Aplicaci�n.
appCls app;

void appCls::leerInscripciones() {
	std::ifstream planillaInscripcion("planillaInscripcion.csv");
	if(!planillaInscripcion) {
		std::cerr << "No se pudo abrir la planilla de inscripciones planillaInscripcion.csv; por favor revise este archivo.\n";
		std::exit(1);
	}
	planillaInscripcion.imbue(commaLocale);
	planillaInscripcion >> std::noskipws;
	while(planillaInscripcion.good()) {
		planillaInscripcion.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		mPropietario.emplace_back();
		planillaInscripcion >> mPropietario.back();
		planillaInscripcion.ignore();
	}
}

void appCls::operator()() {
	leerInscripciones();
}

int main() {
    app();
    return 0;
}
