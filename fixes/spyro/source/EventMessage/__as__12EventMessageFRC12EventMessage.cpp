EventMessage *EventMessage::operator=(const EventMessage &arg0) {
    this->unk0 = (*(UIStringTable **) ChunkData::pCurrentEventStrings)->Add((const char *) arg0.unk0);
    return this;
}
