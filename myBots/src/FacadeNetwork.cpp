/*
 * FacadeNetwork.cpp
 *
 *  Created on: 18/01/2014
 *      Author: esr
 */

#include "FacadeNetwork.h"

FacadeNetwork::FacadeNetwork() {
	_sock.addHandler(this);
	desconected = false;

}

FacadeNetwork::~FacadeNetwork() {
	// TODO !CodeTemplates.destructorstub.tododesc!
}

void FacadeNetwork::initConnection(char* port, char* server){
	boost::asio::io_service io_services;
	_sock.connect(port,server,&io_services);
	io_services.run();

}

void FacadeNetwork::connect(char* port, char* server)
{
	boost::thread t = boost::thread(    [this,port,server]() { initConnection(port,server); } );
}

bool FacadeNetwork::readBuffer(std::string&  buffer)
{
	if(!_newRecuve)
		return false;

	{
		boost::mutex::scoped_lock lock(_recuveMutex);
		buffer = _bufferRecuve;
		_newRecuve = false;
	}
	return true;
}

void FacadeNetwork::send(const std::string & str)
{

	{
		boost::mutex::scoped_lock lock(_sendMutex);
		_bufferSend.push_back(str);
		_newSend = true;
	}
}

void FacadeNetwork::isConnected()
{
	bool isSend=true;

	sendVector();
	_sock.read();
}
void FacadeNetwork::isSendData(){

}
void FacadeNetwork::isRecuveData(boost::asio::streambuf *buf){
	std::istream is(buf);
	bool aux;
	{
		boost::mutex::scoped_lock lockRecuve(_recuveMutex);
		std::getline(is,_bufferRecuve);
		_newRecuve = true;
		aux = desconected;
	}
	sendVector();
	if(!desconected)
		_sock.read();
}

void FacadeNetwork::sendVector(){

	{
		boost::mutex::scoped_lock lock(_sendMutex);
		if(_newSend){
			for(const std::string aux : _bufferSend){
				_sock.send(aux);
				std::cout << "Valor de aux " << aux << "\n";
			}

			_bufferSend.clear();
			_newSend = false;
		}
	}
}

void FacadeNetwork::isCloseConnect()
{
	{
	boost::mutex::scoped_lock lockRecuve(_recuveMutex);
	desconected=true;
	}
}

bool FacadeNetwork::isDisconnected()
{
	bool aux;
	{
		boost::mutex::scoped_lock lockRecuve(_recuveMutex);
		aux = desconected;
	}
	return aux;
}

