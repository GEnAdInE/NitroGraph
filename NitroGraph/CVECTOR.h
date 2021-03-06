#pragma once

#include <iostream>

using namespace std;

template <class T>
class CVector
{
	public:

		//constructors
		CVector();
		CVector(initializer_list<T> ILarrayParam);
		CVector(const CVector& VECParam);

		//mutators
		void VECpush(T value);
		void VECpop();
		bool VECmodify(T element, unsigned int nIndex);
		bool VECdelElement(unsigned int nIndex);
		bool VECdelElementPointer(unsigned int nIndex);
		void VECsetSize(size_t nSize);


		//accessors
		size_t VECsize() const;
		T *VECbegin() const;
		T *VECend() const;
		int VECfind(T element) const;
		T VECgetElement(unsigned int nIndex) const;
		T *VECgetVectorElements() const;


		//operators
		bool operator!=(const CVector<T> &VECvector);

		//destructors
		void VECdelete();
		void VECdelete(unsigned int nIndex);
		~CVector();

	private:

		size_t VECnCapacity;
		T *VECpValueList;

		//misc
		bool VECpointerValueEqual(T element1, T element2) const;

};

/**
 *  @brief		Default constructor of the class.
 */
template <class T>
CVector<T>::CVector() {
	VECnCapacity = 0;
	VECpValueList = NULL;
}

/**
 *  @brief		Comfort constructor of the class.
 *  @param		VECarrayParam	Initializer Array.
 *	@example	CVector<const char*>myVector = { "Hello", "World"};
 */
template<class T>
CVector<T>::CVector(initializer_list<T> ILarrayParam) {
	VECnCapacity = ILarrayParam.VECsize();
	VECpValueList = new T[VECnCapacity];
	unsigned int nValueListIterator = 0;
	for (auto pArrayIterator = ILarrayParam.begin(); pArrayIterator != ILarrayParam.end(); pArrayIterator++) {

		VECpValueList[nValueListIterator] = *pArrayIterator;
		nValueListIterator++;
	}

}

/**
 *  @brief  Copy constructor of the class.
 *  @param  VECParam  CVector to copy.
 *	@example CVector<const char*>myVector2 = myVector;
 */
template<class T>
CVector<T>::CVector(const CVector<T>& VECParam) {
	unsigned int nValueListIterator = 0;
	VECnCapacity = VECParam.VECsize();
	VECpValueList = new T[VECnCapacity];

	T *pvectorValueList = VECParam.VECgetVectorElements();
	for (nValueListIterator; nValueListIterator < VECnCapacity; nValueListIterator++) {
		VECpValueList[nValueListIterator] = pvectorValueList[nValueListIterator];
	}
}

/**
 *  @brief  Push an element inside the vector.
 *  @param  value	New element to push.
 *	@example myVector.VECpush("Hello");
 */
template<class T>
void CVector<T>::VECpush(T value) {

	T *pNewValueList = new T[VECnCapacity + 1];
	unsigned int nNewValueListIterator = 0;
	for (nNewValueListIterator; nNewValueListIterator < VECnCapacity; nNewValueListIterator++) {
		pNewValueList[nNewValueListIterator] = VECpValueList[nNewValueListIterator];
	}

	if (VECpValueList != NULL) delete[] VECpValueList;

	pNewValueList[nNewValueListIterator] = value;
	VECnCapacity++;
	VECpValueList = pNewValueList;
}

/**
 *  @brief  Pop an element from the vector.
*	@throws Empty vector.
 *  @example myVector.VECpop();
 */
template<class T>
void CVector<T>::VECpop() {
	try
	{
		if (VECnCapacity == 0) throw (const char *)"POP ERROR: No element inside vector";
	}
	catch (const char *e)
	{
		cout << e << endl;
		return;
	}

	T *pNewValueList = new T[VECnCapacity - 1];
	unsigned int nNewValueListIterator = 0;
	for (nNewValueListIterator; nNewValueListIterator < VECnCapacity - 1; nNewValueListIterator++) {
		pNewValueList[nNewValueListIterator] = VECpValueList[nNewValueListIterator];
	}
	delete[] VECpValueList;
	VECpValueList = pNewValueList;
	VECnCapacity--;
}

/**
 *  @brief  Return true if the modification has been done correctly, return false otherwise.
 *	@throws Index is out of vector range.
 *  @param  element	 New element to set.
 *	@param	index	 Index of the element that will be modified.
 *	@example myVector.VECmodify("World", 1);
 */
template<class T>
inline bool CVector<T>::VECmodify(T element, unsigned int nIndex) {
	try
	{
		if (nIndex < 0 || nIndex > VECnCapacity - 1) throw (const char *)"MODIFY ERROR: index is out of vector range";
	}
	catch (const char *e)
	{
		cout << e << endl;
		return false;
	}

	VECpValueList[nIndex] = element;
	return true;
}

/**
 *  @brief  Delete an element from the vector.
 *	@throws Index is out of vector range.
 *	@param	index	 Index of the element that will be removed.
 *	@example myVector.VECdelElement(0);
 */
template<class T>
inline bool CVector<T>::VECdelElement(unsigned int nIndex)
{
	try
	{
		if (nIndex < 0 || nIndex > VECnCapacity - 1) throw (const char *)"MODIFY ERROR: index is out of vector range";
	}
	catch (const char *e)
	{
		cout << e << endl;
		return false;
	}

	T *pNewValueList = new T[VECnCapacity - 1];
	unsigned int nNewValueListIterator = 0;
	unsigned int nValueListIterator = 0;
	for (nValueListIterator; nValueListIterator < VECnCapacity; nValueListIterator++) {
		if (nValueListIterator != nIndex) {
			pNewValueList[nNewValueListIterator] = VECpValueList[nValueListIterator];
			nNewValueListIterator++;
		}
	}
	delete[] VECpValueList;
	VECpValueList = pNewValueList;
	VECnCapacity--;
	return true;
}

/**
 *  @brief  Delete a pointer to an element from the vector.
 *	@throws Index is out of vector range.
 *	@param	index	 Index of the element that will be removed.
 *	@example myVector.VECdelElementPointer(0);
 */
template<class T>
inline bool CVector<T>::VECdelElementPointer(unsigned int nIndex)
{
	try
	{
		if (nIndex < 0 || nIndex > VECnCapacity - 1) throw (const char *)"MODIFY ERROR: index is out of vector range";
	}
	catch (const char *e)
	{
		cout << e << endl;
		return false;
	}

	T *pNewValueList = new T[VECnCapacity - 1];
	unsigned int nNewValueListIterator = 0;
	unsigned int nValueListIterator = 0;
	for (nValueListIterator; nValueListIterator < VECnCapacity; nValueListIterator++) {
		if (nValueListIterator != nIndex) {
			pNewValueList[nNewValueListIterator] = VECpValueList[nValueListIterator];
			nNewValueListIterator++;
		}
	}
	VECdelete(nIndex);
	delete[] VECpValueList;
	VECpValueList = pNewValueList;
	VECnCapacity--;
	return true;
}

/**
 *  @brief  Return the size of the vector.
 *	@example size_t myVectorSize = myVector.VECsize();
 */
template<class T>
inline size_t CVector<T>::VECsize() const {
	return VECnCapacity;
}

/**
 *  @brief  Return the address of the first element.
 *	@example const char* myVectorBegin = myVector.VECbegin();
 */
template<class T>
inline T *CVector<T>::VECbegin() const {
	return VECpValueList;
}

/**
 *  @brief  Return the address of the last element.
 *	@example const char* myVectorEnd = myVector.VECend();
 */
template<class T>
inline T *CVector<T>::VECend() const {
	return VECpValueList + VECnCapacity - 1;
}

/**
 *  @brief  Return a pointer pointing to the searched element, if not found return NULL.
 *  @param  element  Element to search in the vector.
 *	@example const char* myWord = myVector.VECfind("Hello");
 */
template<class T>
int CVector<T>::VECfind(T element) const {
	unsigned int nValueListIterator = 0;
	for (nValueListIterator; nValueListIterator < VECnCapacity; nValueListIterator++) {
		if (VECpointerValueEqual(VECpValueList[nValueListIterator], element)) {
			return nValueListIterator;
		}
	}
	return -1;
}

/**
 *  @brief  Return the element stored at index.
 *	@throws Index is out of vector range.
 *  @param  index Index of the element to retrieve.
 *	@example const char* myWord = myVector.VECgetElement(1);
 */
template<class T>
inline T CVector<T>::VECgetElement(unsigned int nIndex) const {
	try
	{
		if (nIndex < 0 || nIndex > VECnCapacity - 1) throw (const char *)"GET ERROR: index is out of vector range";
	}
	catch (const char *e)
	{
		cout << e << endl;
		return T();
	}

	return VECpValueList[nIndex];
}

/**
 *  @brief  Return the whole vector as an Array.
 *	@example const char** mySentence = myVector.VECgetVectorElements();
 */
template<class T>
inline T *CVector<T>::VECgetVectorElements() const {
	return VECpValueList;
}

/**
 *  @brief  Overcharge of != operator
 *	@param	Vector	Vector to compare to
 *	@example myVector1 != myVector2
 */
template<class T>
bool CVector<T>::operator!=(const CVector<T> &VECvector)
{
	if (VECsize() != VECvector.VECsize()) return true;
	
	unsigned int nValueListIterator = 0;
	for (nValueListIterator; nValueListIterator < VECsize(); nValueListIterator++) {
		if (VECgetElement(nValueListIterator) != VECvector.VECgetElement(nValueListIterator)) return true;
	}

	return false;
	
	
}

/**
 *  @brief  Clears a vector of pointer.
 */
template <class T>
void CVector<T>::VECdelete() {
	for (unsigned int nVectorIterator = 0; nVectorIterator < VECnCapacity; nVectorIterator++) {
		delete VECpValueList[nVectorIterator];
	}
}

/**
 *  @brief  Clears a certain pointer from the vector.
 *	@throws Index is out of vector range.
 *  @param  index Index of the element to retrieve.
 *	@example  myVector.VECdelete(1);
 */
template<class T>
inline void CVector<T>::VECdelete(unsigned int nIndex)
{
	try
	{
		if (nIndex < 0 || nIndex > VECnCapacity - 1) throw (const char *)"GET ERROR: index is out of vector range";
	}
	catch (const char *e)
	{
		cout << e << endl;
		return;
	}
	for (unsigned int nVectorIterator = 0; nVectorIterator < VECnCapacity; nVectorIterator++) {
		if (nVectorIterator == nIndex) {
			delete VECpValueList[nVectorIterator];
		}
	}
}
/**
 *  @brief  Destructor of the class
 */
template<class T>
CVector<T>::~CVector() {
	delete[] VECpValueList;
}

/**
 *  @brief  Trick for Matrix, do not use.
 */
template<class T>
void CVector<T>::VECsetSize(size_t nSize)
{
	VECnCapacity = nSize;
}

/**
 *  @brief  Return true if two pointers are deep copies, false otherwise.
 *  @param  element1  First element.
 *  @param  element2  Second element.
 *	@example VECpointerValueEqual(element1, element2);
 */
template<class T>
bool CVector<T>::VECpointerValueEqual(T element1,T element2) const {
	while (*element1) {
		if (*element1 != *element2) {
			return false;
		}
		element1++;
		element2++;
	}
	return true;
}