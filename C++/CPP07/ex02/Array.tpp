/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:28:00 by btani             #+#    #+#             */
/*   Updated: 2024/03/03 12:28:40 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



template <typename T>
Array<T>::Array(void) : _arr(new T[0]), _len(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _len(n) {}

template <typename T>
Array<T>::Array(const Array<T>& copy) : _arr(new T[copy._len])
{
	for (unsigned int i = 0; i < copy._len; ++i)
		_arr[i] = copy._arr[i];
	_len = copy._len;
};

template <typename T>
Array<T>::~Array(void)
{
	if (_len)
		delete[] _arr;
};
		
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& op)
{
	if(this != &op)
	{
		_len = op._len;
		if (_len)
			delete[] _arr;
		_arr = new T[op._len];
		for (unsigned int i = 0; i < _len; ++i)
			_arr[i] = op._arr[i];
	}
	return *this;
};		

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i > static_cast<int>(_len) -1 || i < 0)
		throw Array<T>::OutofBoundsException();
	else
		return _arr[i];
};

template <typename T>
unsigned int Array<T>::size(void) const 
{
	return _len;
};
		