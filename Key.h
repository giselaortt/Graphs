#ifndef KEY_H
#define KEY_H
 
class Key{
	private:
	int value;

	public:
	Key( int value ){
		this->value = value;
	}
	int getValue();
	void setValue( int value );
	Key* copyOf();
	bool operator < ( Key b ) ;
//	bool operator > ( Key b ) const ;
//	bool operator <= ( Key b ) const ;
//	bool operator >= ( Key b ) const ;
	void print();
};

#endif
