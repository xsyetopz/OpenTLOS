template <class T0> class MKPtrList { public: void Destroy(T0 *); };
void MKCollision_RemoveManager(MKCollisionManager *arg0) {
    ((MKPtrList<MKCollisionManager> *) &managers)->Destroy(arg0);
}
