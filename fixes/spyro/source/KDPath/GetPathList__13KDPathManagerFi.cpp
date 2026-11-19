KDPathSegment *KDPathManager::GetPathList(int arg0) {
    return (*(KDPathSegment ***) KDPathManager::pPathLists)[arg0];
}
