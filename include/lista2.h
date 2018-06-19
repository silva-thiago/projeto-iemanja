template <typename T>
LinkedList<T>::LinkedList() {
	head = new struct node<T>;
	head->next = nullptr;

	tail = new struct node<T>;
	tail->next = nullptr;

	length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {

}

template <typename T>
bool LinkedList<T>::IsEmpty() {
	return length == 0;
}

template <typename T>
void LinkedList<T>::PushFront(T content) {
	struct node<T> * newNode = new struct node<T>;
	newNode->content = content;
	newNode->next = head->next;
	head->next = newNode;

	if(IsEmpty())
		tail->next = newNode;

	length++;
}

template <typename T>
void LinkedList<T>::PushBack(T content) {
	struct node<T> * newNode = new struct node<T>;
	newNode->content = content;
	newNode->next = nullptr;

	if(!IsEmpty())
		tail->next->next = newNode;
	
	tail->next = newNode;

	if(IsEmpty())
		head->next = newNode;

	length++;
}

template <typename T>
int LinkedList<T>::Search(T content){
	int position = 0;
	bool found = false;
	struct node<T> * newNode = new struct node<T>;
	newNode = head;	

	while(!found && position < length){
		newNode = newNode->next;	
		if(newNode->content == content){						
			found = true;
		}
		position++;
		
	}
	//retorno do indice
	return position-1;
}

template <typename T>
T LinkedList<T>::GetElement(int index){	
	struct node<T> * newNode = new struct node<T>;
	int position = 0;
	newNode = head;

	while(position-1 < index){
		newNode = newNode->next;
		position++;
	}

	return newNode->content;
}

template <typename T>
void LinkedList<T>::Remove(int index){
	struct node<T> * newNode = new struct node<T>;
	newNode = head;

	for(int i = 0; i <= index-1; i++){
		newNode = newNode->next;
		if(i == index-1){
			std::cout << "Removendo o " << newNode->next->content << std::endl;
			newNode->next = newNode->next->next;			
		}if(i == index){
			newNode->next = nullptr;
		}
	}

	if(length > 0){
		length--;
	}
}

template <typename T>
void LinkedList<T>::Erase(){		
	for(int i = length-1; i >= 0; i--){		
		Remove(i);
	}

	head->next = nullptr;	

	length = 0;
}

template <typename T>	
int LinkedList<T>::Length(){
	return this->length;
}

template <typename T>
void LinkedList<T>::Print() {
	struct node<T> * aux = head->next;

	while(aux != nullptr) {
		std::cout << aux->content << " ";
		aux = aux->next;
	}

	std::cout << std::endl;
}
