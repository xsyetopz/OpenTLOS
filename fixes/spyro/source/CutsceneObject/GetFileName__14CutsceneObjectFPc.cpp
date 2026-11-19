void CutsceneObject::GetFileName(char *arg0) {
    MakeCutsceneFilename(this->GetNumber(), (const char *) this->unk54, arg0, this->unk59 != 0);
}
