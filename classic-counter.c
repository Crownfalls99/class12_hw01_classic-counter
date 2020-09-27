# include "classic-counter.h"


void Pthread_create(pthread_t* thread, const pthread_attr_t* attr, void* (*start_routine)(void*), void* arg) {
	int rc = pthread_create(thread, attr, start_routine, arg);
	assert(rc == 0);
}

void Pthread_join(pthread_t thread, void** value_ptr) {
	int rc = pthread_join(thread, value_ptr);
	assert(rc == 0);
}

void Pthread_mutex_init(pthread_mutex_t* ptr_lock) {
        int rc = pthread_mutex_init(ptr_lock, NULL);
        assert(rc == 0);
}

void Pthread_mutex_lock(pthread_mutex_t* ptr_lock) {
	int rc = pthread_mutex_lock(ptr_lock);
	assert(rc == 0);
}

void Pthread_mutex_unlock(pthread_mutex_t* ptr_lock) {
	int rc = pthread_mutex_unlock(ptr_lock);
	assert(rc == 0);
}

void init(counter_t* c) {
	c->value = 0;
	Pthread_mutex_init(&c->lock);
}

void increment(counter_t* c) {
	Pthread_mutex_lock(&c->lock);
	c->value++;
	Pthread_mutex_unlock(&c->lock);
}

void decrement(counter_t* c) {
	Pthread_mutex_lock(&c->lock);
	c->value--;
	Pthread_mutex_unlock(&c->lock);
}

int get(counter_t* c) {
	return c->value;
}


