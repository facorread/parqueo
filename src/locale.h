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

#include <algorithm>
#include <locale>

/// Objeto de clasificación de caracteres que permite usar una coma para separar datos, para leer archivos .csv con operator>>().
class commaCls : public std::ctype<char> {
	private:
		/// Tabla de clasificación de caracteres.
    mask my_table[table_size];
	public:
		/// Constructor asigna separadores para operator>>().
    commaCls(size_t refs = 0) : std::ctype<char>(&my_table[0], false, refs) {
        std::copy_n(classic_table(), table_size, my_table);
				/// La coma se marca como separador de datos.
        my_table[','] = static_cast<mask>(space);
				/// El espacio se marca como signo de puntuación.
        my_table[' '] = static_cast<mask>(punct);
    }
};

