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

/// Representa la totalidad del programa.
class appCls;

class appCls {
	private:
		/// Representa la lista de propietarios inscritos.
		typedef std::list<propietarioCls> listaPropietariosCls;
		/// Lista de propietarios inscritos.
		listaPropietariosCls mPropietario;
		/// Representa la lista de parqueaderos disponibles.
		/// Lee la lista de propietarios del archivo de inscripciones.
		void leerInscripciones();
	public:
		/// Ejecuta el programa.
		void operator()();
};
